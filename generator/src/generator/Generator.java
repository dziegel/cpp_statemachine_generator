package generator;

import java.io.File;

import javax.xml.XMLConstants;

import org.eclipse.epsilon.egl.EglFileGeneratingTemplateFactory;
import org.eclipse.epsilon.egl.EgxModule;
import org.eclipse.epsilon.egl.formatter.language.JavaFormatter;
import org.eclipse.epsilon.emc.plainxml.PlainXmlModel;
import org.eclipse.epsilon.emc.uml.UmlModel;
import org.eclipse.epsilon.eol.execute.context.Variable;

public class Generator {
	public static void main(String[] args) throws Exception {
		try {
			if (args.length < 2) {
				System.err.println("Usage: java -jar StatemachineGenerator.jar <uml> <out_path> [stereotypename]");
				return;
			}
			
			var filename = args[0];
			var out_path = new File(args[1]).toURI().toString();

			var stereotype = "";
			if (args.length == 3) {
				stereotype = args[2];
			}

			var loader = ClassLoader.getSystemClassLoader();

			var factory = new EglFileGeneratingTemplateFactory();
			factory.setTemplateRoot(loader.getResource("generator/").toString());
			factory.setOutputRoot(out_path);
			factory.setDefaultFormatter(new JavaFormatter());

			if (filename.endsWith(".uml") || filename.endsWith(".xmi")) {
				var tempFile = File.createTempFile("cleaned_", ".uml");
				System.out.println("Cleaning XMI/UML model " + filename);
				RemoveElementsByNamespace.RemoveRootElementsNotMatchingNamespace(filename, tempFile.getAbsolutePath(), "http://www.eclipse.org/uml2/5.0.0/UML");

				System.out.println("Loading XMI/UML model " + filename);
				var uml = new UmlModel();
				uml.setModelFile(tempFile.getAbsolutePath());
				uml.setName("UML");
				uml.putResourceLoadOption(XMLConstants.FEATURE_SECURE_PROCESSING, true);
				uml.load();

				var uml_module = new EgxModule(factory);
				uml_module.parse(loader.getResource("generator/XmiProgram.egx"));
				if (!uml_module.getParseProblems().isEmpty()) {
					System.err.println("Syntax errors found. Exiting.");
					for (var prob : uml_module.getParseProblems()) {
						System.err.println(prob.toString());
					}
					uml.close();
					return;
				}				
				uml_module.getContext().getFrameStack().put(Variable.createReadOnlyVariable("stereotype", stereotype));
				uml_module.getContext().getModelRepository().addModel(uml);
				uml_module.getContext().setUserInput(new UserInput());

				System.out.println("Generating to " + out_path);

				uml_module.execute();
				uml.close();
				
				tempFile.delete();
			}

			if (filename.endsWith(".scxml")) {
				System.out.println("Loading SCXML model " + filename);
				var scxml = new PlainXmlModel();
				scxml.setFile(new File(filename));
				scxml.setName("SCXML");
				scxml.load();

				var scxml_module = new EgxModule(factory);
				scxml_module.parse(loader.getResource("generator/ScxmlProgram.egx"));
				if (!scxml_module.getParseProblems().isEmpty()) {
					System.err.println("Syntax errors found. Exiting.");
					for (var prob : scxml_module.getParseProblems()) {
						System.err.println(prob.toString());
					}
					scxml.close();
					return;
				}

				scxml_module.getContext().getModelRepository().addModel(scxml);
				scxml_module.getContext().setUserInput(new UserInput());

				System.out.println("Generating to " + out_path);

				scxml_module.execute();
				scxml.close();
			}
			System.out.println("Successful");
		} catch (Exception ex) {
			System.out.println("FAILED. Exception: ");
			ex.printStackTrace();
		}
	}
}

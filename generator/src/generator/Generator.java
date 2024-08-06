package generator;

import java.io.File;

import org.eclipse.epsilon.egl.EglFileGeneratingTemplateFactory;
import org.eclipse.epsilon.egl.EgxModule;
import org.eclipse.epsilon.egl.formatter.language.JavaFormatter;
import org.eclipse.epsilon.emc.plainxml.PlainXmlModel;
import org.eclipse.epsilon.emc.uml.UmlModel;

public class Generator {
	public static void main(String[] args) throws Exception {
		try {
			if (args.length != 2) {
				System.err.println("Usage: java -jar StatemachineGenerator.jar <uml> <out_path>");
				return;
			}

			var filename = args[0];
			var out_path = new File(args[1]).toURI().toString();

			var loader = ClassLoader.getSystemClassLoader();

			var factory = new EglFileGeneratingTemplateFactory();
			factory.setTemplateRoot(loader.getResource("generator/").toString());
			factory.setOutputRoot(out_path);
			factory.setDefaultFormatter(new JavaFormatter());

			if (filename.endsWith(".uml") || filename.endsWith(".xmi")) {
				System.out.println("Loading XMI/UML model " + filename);
				var uml = new UmlModel();
				uml.setModelFile(filename);
				uml.setName("UML");
				uml.load();

				var uml_module = new EgxModule(factory);
				uml_module.parse(loader.getResource("generator/XmiProgram.egx"));
				if (!uml_module.getParseProblems().isEmpty()) {
					System.err.println("Syntax errors found. Exiting.");
					for (var prob : uml_module.getParseProblems()) {
						System.err.println(prob.toString());
					}
					return;
				}
				uml_module.getContext().getModelRepository().addModel(uml);
				uml_module.getContext().setUserInput(new UserInput());

				System.out.println("Generating to " + out_path);

				uml_module.execute();
			}

			if (filename.endsWith(".scxml")) {
				System.out.println("Generating SCXML model " + filename);
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
					return;
				}

				scxml_module.getContext().getModelRepository().addModel(scxml);
				scxml_module.getContext().setUserInput(new UserInput());

				System.out.println("Generating to " + out_path);

				scxml_module.execute();
			}
			System.out.println("Successful");
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}

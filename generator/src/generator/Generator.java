package generator;

import java.io.File;
import java.net.URI;

import org.eclipse.epsilon.egl.EglFileGeneratingTemplateFactory;
import org.eclipse.epsilon.egl.EgxModule;
import org.eclipse.epsilon.emc.plainxml.PlainXmlModel;
import org.eclipse.epsilon.emc.uml.UmlModel;
import org.eclipse.epsilon.eol.models.IModel;

public class Generator {
	public static void main(String[] args) throws Exception {
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
		var module = new EgxModule(factory);
		module.parse(loader.getResource("generator/Program.egx"));

		if (!module.getParseProblems().isEmpty()) {
			System.err.println("Syntax errors found. Exiting.");
			for (var prob : module.getParseProblems()) {
				System.err.println(prob.toString());				
			}
			return;
		}

		IModel model = null;
		if (filename.endsWith(".uml") || filename.endsWith(".xmi")) {
			// Load the XML document
			var uml = new UmlModel();
			uml.setModelFile(filename);
			uml.setName("UML");
			uml.load();
			model = uml;

			System.out.println("Generating XMI/UML model " + filename + " to " + out_path);
		}

		if (filename.endsWith(".scxml")) {
			var scxml = new PlainXmlModel();
			scxml.setFile(new File(filename));
			scxml.setName("SCXML");
			scxml.load();
			model = scxml;

			System.out.println("Generating SCXML model " + filename + " to " + out_path);
		}

		// Make the document visible to the EGX program
		module.getContext().getModelRepository().addModel(model);
		// ... and execute
		module.execute();
	}
}

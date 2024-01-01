import java.io.File;
import org.eclipse.epsilon.egl.EglFileGeneratingTemplateFactory;
import org.eclipse.epsilon.egl.EgxModule;
import org.eclipse.epsilon.emc.plainxml.PlainXmlModel;
import org.eclipse.epsilon.emc.uml.UmlModel;
import org.eclipse.epsilon.eol.models.IModel;

public class Generator {
  public static void main(String[] args) throws Exception {
	if (args.length == 0) {
	   System.err.println("Missing file argument.");
	   return;
	}

	var factory = new EglFileGeneratingTemplateFactory();
	factory.setTemplateRoot(Generator.class.getProtectionDomain().getCodeSource().getLocation().toURI().toURL().toString());
	factory.setTemplateRoot("/home/dziegel/event_framework/cpp_statemachine_generator/generator/src");
    var module = new EgxModule(factory);
    module.parse(new File("/home/dziegel/event_framework/cpp_statemachine_generator/generator/src/Program.egx").getAbsoluteFile());

    if (!module.getParseProblems().isEmpty()) {
      System.err.println("Syntax errors found. Exiting.");
      return;
    }

    IModel model = null;
    
    var filename = args[0];
    if (filename.endsWith(".uml") || filename.endsWith(".xmi"))
    {
        // Load the XML document
        var uml = new UmlModel();
        uml.setModelFile(args[0]);
        uml.setName("UML");
        uml.load();
        model = uml;
        
        System.out.println("Generating XMI/UML model " + filename);
    }
    
    if (filename.endsWith(".scxml"))
    {
        var scxml = new PlainXmlModel();
        scxml.setFile(new File("library.xml"));
        scxml.setName("SCXML");
        scxml.load();
        model = scxml;

        System.out.println("Generating SCXML model " + filename);
}

    // Make the document visible to the EGX program
    module.getContext().getModelRepository().addModel(model);
    // ... and execute
    module.execute();
  }
}  

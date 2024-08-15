package generator;

import java.io.File;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class RemoveElementsByNamespace {
    public static void RemoveRootElementsNotMatchingNamespace(String xmlFilePath, String outFilePath, String targetNamespace) {
        try {
            // Create a document builder factory
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            factory.setNamespaceAware(true);

            // Create a document builder
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parse the XML file and get the document object
            Document document = builder.parse(new File(xmlFilePath));
            
            // Get the root element
            Element root = document.getDocumentElement();

            if (root.getNamespaceURI() != targetNamespace) {
            	// Remove elements that do not match the namespace
            	removeElementsByNamespace(root, targetNamespace);
            }
            
            // Save the updated XML document to a new file
            saveDocumentToFile(document, outFilePath);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void removeElementsByNamespace(Element element, String namespace) {
        NodeList childNodes = element.getChildNodes();

        for (int i = childNodes.getLength() - 1; i >= 0; i--) {
            Node node = childNodes.item(i);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element childElement = (Element) node;

                // Remove the element if it does not match the namespace
                if (!namespace.equals(childElement.getNamespaceURI())) {
                    element.removeChild(childElement);
                }
            }
        }
    }

    private static void saveDocumentToFile(Document document, String filePath) throws Exception {
        // Create a transformer factory
        TransformerFactory transformerFactory = TransformerFactory.newInstance();

        // Create a transformer
        Transformer transformer = transformerFactory.newTransformer();
        transformer.setOutputProperty(OutputKeys.INDENT, "yes");

        // Create a DOM source and a stream result
        DOMSource source = new DOMSource(document);
        StreamResult result = new StreamResult(new File(filePath));

        // Transform the document to a file
        transformer.transform(source, result);
    }
}

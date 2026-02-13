#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// Abstraction for Document Elements
class DocumentElement {
    public:
    virtual string render() = 0; // Pure virtual function for rendering the element
};

// Concrete implementation for Paragraph
class TextElement : public DocumentElement {
    private:
    string text;

    public:
    TextElement(string text) {
        this->text = text;
    }

    string render() override {
        return text; // Render the text as is
    }
};

// Concrete implementation for Image
class ImageElement : public DocumentElement {
    private:
    string imagePath;

    public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }
    string render() override {
        return "[Image: " + imagePath + "]"; // Render the image as a placeholder
    }
};

// NewLineElement represents a new line in the document
class NewLineElement : public DocumentElement {
    public:
    string render() override {
        return "\n"; // Render a new line
    }
};

// TabsSpaceElement represents a tab space in the document
class TabsSpaceElement : public DocumentElement {
    public:
    string render() override {
        return "\t"; // Render a tab space
    }
};

// Document class responsible for holding a collection of elements
class Document {
    private:
    vector<DocumentElement*> elements; // Collection of document elements

    public:
    void addElement(DocumentElement* element) {
        elements.push_back(element); // Add an element to the document
    }

    string render() {
        string result;
        for (auto element : elements) {
            result += element->render(); // Render each element and concatenate the results
        }
        return result; // Return the complete rendered document
    }
};

// Persistance abstraction
class Persistence {
    public:
    virtual void save(string data) = 0; // Pure virtual function for saving data
};

// FileStorage clas implementing Persistence to save data to a file
class FileStorage : public Persistence {
    private:
    string filename;

    public:
    FileStorage(string filename) {
        this->filename = filename;
    }

    void save(string data) override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << data; // Write the data to the file
            outFile.close(); // Close the file after writing
        } else {
            cerr << "Unable to open file: " << filename << endl; // Handle file opening errors
        }
    }
};

// PlaceHolder DBStorage Implementation
class DBStorage : public Persistence {
    public:
    void save(string data) override {
        // Placeholder for database storage implementation
        cout << "Saving to database: " << data << endl; // Simulate saving to a database
    }
};

// DocumentEditor class responsible for managing the document and its persistence
class DocumentEditor {
    private:
    Document document; // The document being edited
    Persistence* persistence; // The persistence mechanism for saving the document

    public:
    DocumentEditor(Persistence* persistence) {
        this->persistence = persistence;
    }

    void addElement(DocumentElement* element) {
        document.addElement(element); // Add an element to the document
    }

    void saveDocument() {
        string renderedDocument = document.render(); // Render the document
        persistence->save(renderedDocument); // Save the rendered document using the persistence mechanism
    }
};

int main() {
    // Create a DocumentEditor with FileStorage persistence
    DocumentEditor editor(new FileStorage("document.txt"));

    // Add elements to the document
    editor.addElement(new TextElement("Hello, this is a sample document."));
    editor.addElement(new NewLineElement());
    editor.addElement(new TextElement("This document is created using the DocumentEditor class."));
    editor.addElement(new NewLineElement());
    editor.addElement(new ImageElement("image.png"));
    editor.addElement(new TabsSpaceElement());
    editor.addElement(new TextElement("End of the document."));

    // Save the document
    editor.saveDocument();

    return 0;
}
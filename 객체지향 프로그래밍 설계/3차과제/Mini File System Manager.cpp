#include <iostream>
#include <string>
using namespace std;

class Entry {
protected:
    string name;

    static bool isValidName(const string& s) {
        if (s.empty()) return false;

        int i;
        for (i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '/' || s[i] == ' ') return false;
        }
        return true;
    }

    static void indent(int depth) {
        int i;
        for (i = 0; i < depth; ++i) {
            cout << "  ";
        }
    }

public:
    Entry(const string& name) : name(name) {
        if (!isValidName(name)) {
            throw 1;
        }
    }

    virtual ~Entry() {}

    string getName() const {
        return name;
    }

    virtual int getSize() const = 0;
    virtual void print(int depth) const = 0;
};

class File : public Entry {
protected:
    int size;

public:
    File(const string& name, int size) : Entry(name), size(size) {
        if (size < 0) {
            throw 1;
        }
    }

    int getSize() const {
        return size;
    }
};

class TextFile : public File {
private:
    int lines;

public:
    TextFile(const string& name, int size, int lines)
        : File(name, size), lines(lines) {
        if (lines < 0) {
            throw 1;
        }
    }

    void print(int depth) const {
        // TODO
        if (depth != 0) cout << endl;
        indent(depth);
        cout << "[TXT] " << name << " " << getSize() << " " << lines;
    }
};

class ImageFile : public File {
private:
    int width;
    int height;

public:
    ImageFile(const string& name, int size, int width, int height)
        : File(name, size), width(width), height(height) {
        if (width <= 0 || height <= 0) {
            throw 1;
        }
    }

    void print(int depth) const {
        // TODO
        if (depth != 0) cout << endl;
        indent(depth);
        cout << "[IMG] " << name << " " << getSize() << " " << width << "x" << height;
    }
};

class Directory : public Entry {
private:
    Entry** children;
    int count;
    int capacity;

public:
    Directory(const string& name, int capacity)
        : Entry(name), count(0), capacity(capacity) {
        if (capacity <= 0) throw 1;
        else {
            children = new Entry * [capacity];
        }
    }

    virtual ~Directory() {
        for (int i = 0; i < count; i++) {
            delete children[i];
        }
        delete[] children;
    }

    Entry* findEntry(const string& childName) const {
        // TODO
        for (int i = 0; i < count; i++) {
            if (children[i]->getName() == childName)
                return children[i];
        }

        return NULL;
    }

    void addEntry(Entry* e) {
        // TODO:
        // Hint:
        // if insertion fails, remember that the new entry e was just created
        // and should not be leaked.
        // if full, delete e and throw exception
        // if duplicate name, delete e and throw exception
        // insert e
        
        //예외 처리
        if (e == NULL || count == capacity) {
            delete e;
            throw 1;
        }

        for (int i = 0; i < count; i++) {
            string temp = children[i]->getName();
            if (temp == e->getName()) {
                delete e;
                throw 1;
            }
        }

        children[count++] = e;

    }

    void removeEntry(const string& childName) {
        // TODO:
        // find child
        // if not found, throw exception
        // delete target
        // shift array
        Entry* find = findEntry(childName);
        if (find == NULL) {
            throw 1;
        }
        else {
            for (int i = 0; i < count; i++) {
                if (find == children[i]) {
                    delete children[i];
                    count--;
                    for (int j = i; j < count; j++) {
                        children[j] = children[j + 1];
                    }
                    break;
                }
            }
        }
    }

    int getSize() const {
        // TODO:
        // return recursive sum of child sizes
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += children[i]->getSize();
        }
        return sum;

        return 0;
    }

    void print(int depth) const {
        // TODO:
        // print current directory
        // recursively print children
        if (depth != 0) cout << endl;
        indent(depth);
        cout << "[DIR] " << name << " " << getSize();
        for (int i = 0; i < count; i++) {
            children[i]->print(depth+1);
        }
    }
};

class FileSystem {
private:
    Directory* root;

    static bool isValidAbsolutePath(const string& path) {
        return (!path.empty() && path[0] == '/');
    }

    static string getParentPath(const string& path) {
        if (path == "/")
            return "/";

        int end = path.rfind("/");
        if (end == 0) {
            return "/";
        }

        string result = path.substr(0, end);
        return result;

        return "";
    }

    static string getBaseName(const string& path) {
        if (path == "/")
            return "/";

        int end = path.rfind("/");

        string result = path.substr(end+1);
        return result;

        return "";
    }

public:
    FileSystem() {
        // TODO:
        // create root directory with capacity 1000
        root = new Directory("root", 1000);
    }

    ~FileSystem() {
        delete root;
    }

    Entry* resolve(const string& path) const {
        if (!isValidAbsolutePath(path))
            throw 1;

        if (path == "/") return root;

        Entry* entry_temp = root;
            
        int start = 1;
        while (start < path.size()) {
            int pos = path.find('/', start);
            string sub;

            if (pos == string::npos) {
                sub = path.substr(start);
                start = path.size();
            }
            else {
                sub = path.substr(start, pos-start);
                start = pos+1;
            }

            Directory* temp = dynamic_cast<Directory*>(entry_temp);
            //못찾았을때 오류
            if (temp == NULL)
                throw 1;

            Entry* next = temp->findEntry(sub);

            //못찾았을때 오류
            if (next == NULL)
                throw 1;

            entry_temp = next;
        }
        return entry_temp;

        return NULL;
    }

    Directory* resolveDirectory(const string& path) const {
        // TODO:
        // Hint:
        // first resolve the path, then check whether the result is a Directory.
        // resolve path and make sure it is a directory

        Entry* temp = resolve(path);
        Directory* result = dynamic_cast<Directory*>(temp);

        if (result == NULL)
            throw 1;
        else
            return result;

        return NULL;
    }

    void mkdir(const string& parentPath, const string& name, int capacity) {
        // TODO
        Directory* parent = resolveDirectory(parentPath);
        
        if (parent == NULL)
            throw 1;

        Entry* result = new Directory(name, capacity);
        parent->addEntry(result);
    }

    void addText(const string& parentPath, const string& name, int size, int lines) {
        // TODO
        Directory* parent = resolveDirectory(parentPath);

        if (parent == NULL)
            throw 1;

        Entry* result = new TextFile(name, size, lines);
        parent->addEntry(result);
    }

    void addImage(const string& parentPath, const string& name, int size, int width, int height) {
        // TODO
        Directory* parent = resolveDirectory(parentPath);

        if (parent == NULL)
            throw 1;

        Entry* result = new ImageFile(name, size, width, height);
        parent->addEntry(result);
    }

    void removePath(const string& path) {
        // TODO:
        // Hint:
        // removing "/" is invalid.
        // It may help to resolve the parent directory first, then remove the target child.
        if (path == "/")
            throw 1;

        string parent_dir = getParentPath(path), base_dir = getBaseName(path);
        
        Directory* parent = resolveDirectory(parent_dir);
        parent->removeEntry(base_dir);
    }
};

int main() {
    FileSystem fs;

    int Q;
    cin >> Q;

    int i;
    for (i = 0; i < Q; ++i) {
        string cmd;

        try {
            cin >> cmd;

            if (cmd == "MKDIR") {
                string parentPath, name;
                int capacity;
                cin >> parentPath >> name >> capacity;
                fs.mkdir(parentPath, name, capacity);
            }
            else if (cmd == "ADDTEXT") {
                string parentPath, name;
                int size, lines;
                cin >> parentPath >> name >> size >> lines;
                fs.addText(parentPath, name, size, lines);
            }
            else if (cmd == "ADDIMAGE") {
                string parentPath, name;
                int size, width, height;
                cin >> parentPath >> name >> size >> width >> height;
                fs.addImage(parentPath, name, size, width, height);
            }
            else if (cmd == "REMOVE") {
                string path;
                cin >> path;
                fs.removePath(path);
            }
            else if (cmd == "SIZE") {
                string path;
                cin >> path;
                cout << fs.resolve(path)->getSize() << "\n";
            }
            else if (cmd == "PRINT") {
                string path;
                cin >> path;
                Entry* target = fs.resolve(path);
                target->print(0);
                cout << "\n";
            }
            else {
                throw 1;
            }
        }
        catch (...) {
            cout << "ERROR\n";
        }
    }

    return 0;
}

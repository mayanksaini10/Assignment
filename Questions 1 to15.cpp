
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> // for sort, unique
using namespace std;

// 1. Reverse a string using loop
string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

// 2. Replace substrings
string replaceSubstring(string str, string from, string to) {
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
    return str;
}

// 3. Linear search
bool linearSearch(vector<int> arr, int key) {
    for (int x : arr) {
        if (x == key) return true;
    }
    return false;
}

// 4. Bubble sort
void bubbleSort(vector<int>& arr, bool ascending = true) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j+1]) || (!ascending && arr[j] < arr[j+1])) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 5. Reverse an array
void reverseArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

// 6. Remove duplicates
vector<int> removeDuplicates(vector<int> arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

// 7. Merge two sorted arrays
vector<int> mergeArrays(vector<int> a, vector<int> b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);
    return merged;
}

// 8. Read from a file
void readFile(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found!\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// 9. Copy file
void copyFile(string src, string dest) {
    ifstream in(src, ios::binary);
    ofstream out(dest, ios::binary);
    if (!in || !out) {
        cout << "Error opening files!\n";
        return;
    }
    out << in.rdbuf();  // copy buffer directly
    in.close();
    out.close();
}

// 10. Search word in file
void searchInFile(string filename, string word) {
    ifstream file(filename);
    if (!file) {
        cout << "File not found!\n";
        return;
    }
    string line;
    int lineNo = 1;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(word) != string::npos) {
            cout << "Found in line " << lineNo << ": " << line << endl;
            found = true;
        }
        lineNo++;
    }
    if (!found) cout << "Word not found in file.\n";
    file.close();
}

// Main function to test
int main() {
    // 1
    cout << "Reversed string: " << reverseString("Hello World") << endl;

    // 2
    cout << "Replaced string: " << replaceSubstring("I like apples. apples are good.", "apples", "oranges") << endl;

    // 3
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << "Linear search 30: " << (linearSearch(arr, 30) ? "Found" : "Not Found") << endl;

    // 4
    bubbleSort(arr, true);
    cout << "Bubble sorted ascending: ";
    for (int x : arr) cout << x << " "; cout << endl;

    // 5
    reverseArray(arr);
    cout << "Reversed array: ";
    for (int x : arr) cout << x << " "; cout << endl;

    // 6
    vector<int> arrDup = {1,2,2,3,4,4,5};
    vector<int> noDup = removeDuplicates(arrDup);
    cout << "Array without duplicates: ";
    for (int x : noDup) cout << x << " "; cout << endl;

    // 7
    vector<int> a = {1,3,5};
    vector<int> b = {2,4,6};
    vector<int> merged = mergeArrays(a,b);
    cout << "Merged array: ";
    for (int x : merged) cout << x << " "; cout << endl;

    // 8 (reading file)
     readFile("test.txt");

    // 9 (copy file)
    copyFile("test.txt", "copy.txt");

    // 10 (search word in file)
     searchInFile("test.txt", "apple");

    return 0;
}

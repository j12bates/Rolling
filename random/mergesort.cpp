#include <iostream>
#include <vector>

using namespace std;

// Just declarations so my code can be in the right order
vector<int> mergeSortedLists(vector<int>, vector<int>);
vector<vector <int>> mergeAllLists(vector<vector <int>>);
void printVector(vector<int>);

// Commenter's Note: when I say 'list', I mean 'vector'

int main(int argc, char *argv[])
{
    // Input size
    int size;
    cin >> size;

    // Input each number into a singleton list
    int num;
    vector<vector <int>> work (size);
    for (int i = 0; i < size; i++) {
        cin >> num;
        work[i] = {num};
    }

    // Merge pairs of lists until there is only one list
    while (work.size() > 1) work = mergeAllLists(work);

    // Output numbers
    for (int i = 0; i < work[0].size(); i++) {
        cout << work[0][i] << " ";
    }
    cout << endl;
}

// Take a list of lists, merge the adjacent pairs of lists, return that as a new list
vector<vector <int>> mergeAllLists(vector<vector <int>> data)
{
    // The result size is half (since we're merging pairs of lists), plus one if there's a spare
    vector<vector <int>> result (data.size() / 2 + data.size() % 2);

    // Index two at a time, merge both lists
    for (int i = 0; i + 1 < data.size(); i += 2) {
        result[i / 2] = mergeSortedLists(data[i], data[i + 1]);
    }

    // If there's a spare, just place it at the end
    if (data.size() % 2) result[data.size() / 2] = data[data.size() - 1];

    return result;
}

// Take two lists that are already sorted, merge them to create one sorted list
vector<int> mergeSortedLists(vector<int> a, vector<int> b)
{
    // The size is the sum of the lengths of the two lists
    vector<int> result (a.size() + b.size());

    // Keep pointers for the lowest value of each list so far
    int i = 0;  // I is ptr for list A
    int j = 0;  // J is ptr for list B

    // ====== THIS IS THE IMPORTANT BIT ======
    while (i < a.size() && j < b.size()) {  // Merge until one list is exhausted
        if (a[i] < b[j]) {                  // For whichever list has the lower value
            result[i + j] = a[i];           // Append its value to the result
            i++;                            // And move to the next item (inc ptr)
        } else {
            result[i + j] = b[j];
            j++;
        }
    }

    // Append whatever remains from the unexhausted list
    for (; i < a.size(); i++) result[i + j] = a[i];
    for (; j < b.size(); j++) result[i + j] = b[j];

    return result;
}

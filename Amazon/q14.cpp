#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
    // pepcoding
public:
    int ans = 0;
    void downNode(Node *root, Node *block, int bt)
    {
        if (!root or root == block)
        {
            return;
        }
        ans = max(ans, bt);
        downNode(root->left, block, bt + 1);
        downNode(root->right, block, bt + 1);
    }
    int findNode(Node *root, int target)
    {
        if (!root)
        {
            return -1;
        }
        if (root->data == target)
        {
            downNode(root, NULL, 0);
            return 1;
        }
        int l = findNode(root->left, target);
        if (l != -1)
        {
            downNode(root, root->left, l);
            return l + 1;
        }
        int r = findNode(root->right, target);
        if (r != -1)
        {
            downNode(root, root->right, r);
            return r + 1;
        }
        return -1;
    }
    int minTime(Node *root, int target)
    {
        findNode(root, target);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}
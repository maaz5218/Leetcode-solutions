struct Node
{
    Node* link[26];
    bool isEnd;
    Node()
    {
        for(int i=0;i<26;i++)
        link[i]=nullptr;
            isEnd=false;
    }
};
class Trie
{
    Node* root;
public:
Trie()
{
    root=new Node();
}
void insert(string word)
{
    Node* node=root;
    for(char ch:word)
    {
    int idx=ch-'a';
    if(node->link[idx]==nullptr)
    {
    node->link[idx]=new Node();
    }
    node=node->link[idx];
    }
    node->isEnd=true;
}
bool search(string word)
{
    Node* node=root;
    for(char ch:word)
    {
    int idx=ch-'a';
    if(node->link[idx]==nullptr)
    return false;
    node=node->link[idx];
    }
    return node->isEnd;
}
bool startsWith(string prefix)
{
    Node* node=root;
    for(auto ch:prefix)
    {
    int idx=ch-'a';
    if(node->link[idx]==nullptr)
    return false;
    node=node->link[idx];
    }
    return true;
}
};
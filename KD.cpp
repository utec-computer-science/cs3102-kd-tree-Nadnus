#include <iostream>
#include <utility>
#include<vector>
using namespace std;
class KD
{
    using coord = pair<int, int>;
    class node;

private:
    int degree;
    node *root;

    class node
    {
        node *parent;
        node *right_node;
        node *left_node;
        coord content;
        int depth;

    public:
        node(coord future_content)
        {
            content = future_content;
            parent = nullptr;
            right_node = nullptr;
            left_node = nullptr;
            depth = 0;
        };
        void setParent(node *parent_pointer)
        {
            parent = parent_pointer;
            depth = (parent->depth) + 1;
            
        }
        void setRight(node *right)
        {
            right_node = right;
        }
        void setLeft(node *left)
        {
            left_node = left;
        }
        void insertNode(node *inserted_node)
        {
            int current = depth % 2;
            int used_coord_to_insert;
            int used_coord_current_node;
            if (current == 0)
            {
                used_coord_to_insert = inserted_node->content.first;
                used_coord_current_node = content.first;
            }
            else
            {
                used_coord_to_insert = inserted_node->content.second;
                used_coord_current_node = content.second;
            }
            if (used_coord_to_insert > used_coord_current_node)
            {
                //insert right
                if (right_node == nullptr)
                    {setRight(inserted_node);
                    inserted_node->setParent(this);}
                else
                    right_node->insertNode(inserted_node);
            }
            else
            {
                //insert left
                if (left_node == nullptr)
                    {setLeft(inserted_node);
                    inserted_node->setParent(this);}
                else
                    left_node->insertNode(inserted_node);
            }
        }
    };

public:
    void insertInRoot(coord node_coordinate)
    {
        node * new_node = new node(node_coordinate);
        if (root == nullptr)
        {
            root = new_node;
        }
        else
        {
            root->insertNode(new_node);
        }
    }
    KD(/* args */)
    {
        root = nullptr;
    };
    ~KD(){

    };
};
int main(){
    vector<pair<int,int>> coordinates;
    int x,y;
    KD my_kd = KD();
    while(cin>>x>>y){
        pair<int,int> temp = make_pair(x,y);
        coordinates.push_back(temp);
        cout<<temp.first<<temp.second;
    }
    for(pair<int,int> my_pair : coordinates){
       my_kd.insertInRoot(my_pair); 
    }
}
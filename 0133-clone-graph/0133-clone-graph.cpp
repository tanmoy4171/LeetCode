

class Solution
{
    public:
        Node* cloneGraph(Node *node)
        {
            
            if(node==NULL){
                return NULL;
            }
            vector<int> vis(101, 0);
            vector<Node*> visA(101);
            queue<Node*> q;
            q.push(node);
            vis[node->val] = 1;
       
            
            Node *k = new Node;
            k->val = node->val;
            visA[node->val] = k;

            while (!q.empty())
            {
                Node *node1 = q.front();
                q.pop();
                vector<Node*> visNodeNeighbor;
                for (auto it: node1->neighbors)
                {
                    if (!vis[it->val])
                    {
                        q.push(it);
                        vis[it->val] = 1;

                        Node *p = new Node;
                        p->val = it->val;
                        visA[it->val] = p;
                    }

                    visNodeNeighbor.push_back(visA[it->val]);
                    
                }
                
                visA[node1->val]->neighbors=visNodeNeighbor;
            }
            
            return k;
        }
};
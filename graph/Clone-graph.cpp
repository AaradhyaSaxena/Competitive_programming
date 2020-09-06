//////////https://www.interviewbit.com/problems/clone-graph/

///// clone graph

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *graph) {
    if (!graph) return NULL;

    map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    queue<UndirectedGraphNode *> q;
    q.push(graph);

    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
    map[graph] = graphCopy;

    while (!q.empty()) {
        UndirectedGraphNode *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            // no copy exists
            if (map.find(neighbor) == map.end()) {
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            } else {     // a copy already exists
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }
    return graphCopy;
}

////////////////////

// UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
//     unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
//     if(!node)
//         return NULL;
//     UndirectedGraphNode *root = NULL;
//     queue<UndirectedGraphNode*> qu;
//     qu.push(node);
//     root = new UndirectedGraphNode(node->label);
//     mp.insert(make_pair(node, root));
//     while (!qu.empty())
//     {
//         UndirectedGraphNode *t = NULL;
//         t = qu.front();
//         qu.pop();
//         UndirectedGraphNode *pt = NULL;
//         pt = mp.find(t)->second;
               
//         for (int i = 0; i < t->neighbors.size(); i++)
//         {
//             if (mp.find(t->neighbors[i]) == mp.end())
//             {
//                 UndirectedGraphNode *n = new UndirectedGraphNode (t->neighbors[i]->label);
//                 mp.insert(make_pair(t->neighbors[i],n));
                
                
//                 pt->neighbors.push_back(n);
                
//                 qu.push(t->neighbors[i]);
//             }
//             else
//             {
//                 UndirectedGraphNode *p = NULL;
//                 p = mp.find(t->neighbors[i])->second;
                
//                 pt->neighbors.push_back(p);
//             }
//         }
//     }
//     return root;
// }

/////
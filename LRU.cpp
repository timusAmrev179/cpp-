/*
	problem in geeks for geeks. LRU Implementation. 
	input : No. of testcases t
		queries q, capacity c, 
		followed by q lines of queries like SET 1 2 GET 1 

*/


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{
private:
	int cap; 
	list<pair<int, int>> dll; 
	unordered_map<int, list<pair<int, int>> :: iterator> umap; 
public:
    LRUCache(int cap)
    {
        this->cap= cap;
	dll.clear(); 	
	umap.clear(); 
    }
    
    int get(int key)
    {
        int res = -1; 
	if(!umap.count(key)) return res; 
	else{
		auto it= umap.find(key); 
		res = it->second->second; 

		//cout<<"inside fun: "<< res<<endl; 

		dll.erase(it->second); 
		dll.push_front({key, res}); 
		umap[key] = dll.begin(); 
		
	}
 
	return res; 
    }
    
    void set(int key, int value)
    {
       	if(!umap.count(key)){
		if(dll.size() == cap){
			int rkey = dll.back().first;
			umap.erase(rkey); 
			dll.pop_back(); 
			dll.push_front({key, value}); 
			umap[key] = dll.begin();   
		}else{

			dll.push_front({key, value}); 
			umap[key] = dll.begin(); 
		}
	}else{

		auto it = umap[key]; 
		dll.erase(it);
		dll.push_front({key, value}); 
		umap[key] = dll.begin();  
		

	}



    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends

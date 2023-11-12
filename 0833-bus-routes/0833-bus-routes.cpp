class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (target == source ) return 0;
        
        // hash maps of stops to routes and visitation map for routes
        unordered_map<int,vector<int>> stops;
        unordered_map<int, int> visitedRoute;

        //bfs queue
        queue<pair<int,int>> q;
        
        // go through all routes and stops to create a map of all routes from each bus stop
        for (int i = 0 ; i < routes.size(); i++) {
            auto route = routes[i];
            for (int k = 0; k < route.size(); k++) {
                auto currentStop = route[k];
                if (stops.find(currentStop) == stops.end()){
                    vector<int> a;
                    stops[currentStop] = a;
                }
                stops[currentStop].push_back(i);
            }
        } 
        
        // now stops is a map of all routes connected to a single stop
        // by design routes is a map of all stops connected to a single route
        
        //now map all routes to every route
        unordered_map<int, set<int>> routeMap;
        
        for (int i = 0 ; i < routes.size(); i++) {
            auto route = routes[i];
            set<int> a;
            routeMap[i] = a;
            for (int k = 0; k < route.size(); k++) {
                auto currentStop = route[k];
                for (auto connectingRoute : stops[currentStop]) {
                    routeMap[i].insert(connectingRoute);
                }
            }
        } 
        //now we have a graph of all routes
        
        //imagine a new route with only one start and end which is just the source start
		// this way we have a start point which allows us to search all bus routes from our current stop
        set<int> soloRoute;
        for (int i = 0; i < stops[source].size(); i++) {
            soloRoute.insert(stops[source][i]);
        }
        
        routeMap[routes.size()] = soloRoute;
        
        // start a BFS through the route graph starting at your route        
        q.push(make_pair(0, routes.size()));
        visitedRoute[routes.size()] = 1;
            
        // take all connecting routes
        
        while (q.size() > 0) {
            int currentDistance = q.front().first;
            int currentRoute = q.front().second;
            q.pop();
            
            //check to see if the busstop is on your current route
            // if the bus stop is in this routes bus stop list youre done
            if (currentRoute != routes.size() && find(routes[currentRoute].begin(), routes[currentRoute].end(), target) != routes[currentRoute].end()) return currentDistance;
            
            // go through all routes connecting to yours
            for (auto connectingRoute : routeMap[currentRoute]) {
                //check if weve already checked the route
                if (visitedRoute.find(connectingRoute) == visitedRoute.end()) {
                    // we havent visited this route yet
                    
                    //visit and search this route
                    visitedRoute[connectingRoute] = 1;
                    q.push(make_pair(currentDistance + 1, connectingRoute));
                }
            }
            
        }
       // not found 
        return -1;
        
    }
};
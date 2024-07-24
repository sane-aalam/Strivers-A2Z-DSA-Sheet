// Every node has n-1 options to connect with. so n*(n-1)
// But in question, it is given an undirected graph so an edge from both the node is same only therefore we will divide it by 2 =  (n*(n-1))/2
// As a node has 2 options, either it will be connected with other node, or will not be connected with any other node so we will retire pow(2,x)
// Each of the possible edges can either be present or absent.
// This gives us 2 choices (present or absent) per edge.
// The total number of undirected graphs is 2raised to the power of the number of possible edges.
// Therefore, the formula is 2^( (n*(n-1))/2 ).
//         int x;
        
//         x = (n*(n-1))/2;
//         return pow(2,x);
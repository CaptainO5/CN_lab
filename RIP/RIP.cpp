#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_NODES = 5;
const int INF = 100000;

class RT {
    private:
        char *Dests;
        int *Costs;
        char *NextHops;
    public:
        char nodeName;
        RT(){
            this -> Dests = new char[NUM_NODES];
            this -> Costs = new int[NUM_NODES];
            this -> NextHops = new char[NUM_NODES];
        }

        void display(){
            cout << "  -----------------------------------\n";
            cout << setw(15) << "Destination " << setw(10) << "|  Cost  | Next Hop"<<endl;
            cout << "  -----------------------------------\n";
            for (int i = 0; i < NUM_NODES; i++){
                cout << setw(14) << Dests[i] << " | ";
                (Costs[i] == INF)?cout << setw(6) << "INF":cout << setw(6) << Costs[i];
                cout << " | " << NextHops[i] << "\n";
            }
        }

        char* getDests(){
            return this -> Dests;
        }

        int* getCosts(){
            return this -> Costs;
        }

        void init(char name){
            for (int i = 0; i < NUM_NODES; i++){
                this -> Dests[i] = 'A' + i;
                this -> Costs[i] = (name == 'A' + i)?0:INF;
                this -> NextHops[i] = 0;
            }
        }

        void update(char dest, int cost, char nextHop){
            int idx = dest - 'A';
            Costs[idx] = cost;
            NextHops[idx] = nextHop;
        }

};

class Node {
    public:
        RT rt;
        char name;

        Node(){
            // Do Nothing
        }

        void init(char nodeName){
            this -> name = nodeName;
            this -> rt.init(name);
        }

        void getRTinfo(char **To, int **Costs, char *from){
            *To = rt.getDests();
            *Costs = rt.getCosts();
            *from = this -> name;
        }
};

void DV(Node *Network, int node_idx){
    for (int i = 0; i < NUM_NODES; i++){

        // get information from other nodes and update Routing table
        if (i != node_idx){
            char *to;
            char from;
            int *costs;
            Network[i].getRTinfo(&to, &costs, &from);

            int *i_costs = Network[node_idx].rt.getCosts();

            int stoi = i_costs[i];

            for (int id = 0; id < NUM_NODES; id++){
                int stod = stoi + costs[id];
                if (stod < i_costs[id]){
                    Network[node_idx].rt.update(to[id], stod, from);
                }
            }
        }
    }
}

int main(){
    Node Network[NUM_NODES];
    for (int i = 0; i < 5; i++){
        Network[i].init('A' + i);
    }

    // Network building as in "Network.png"
    // For Node A:
    Network[0].rt.update('B', 1, 'B');
    Network[0].rt.update('C', 5, 'C');

    // For B:
    Network[1].rt.update('A', 1, 'A');
    Network[1].rt.update('C', 3, 'C');
    Network[1].rt.update('E', 9, 'E');

    // For C:
    Network[2].rt.update('A', 5, 'A');
    Network[2].rt.update('B', 3, 'B');
    Network[2].rt.update('D', 4, 'D');

    // For D:
    Network[3].rt.update('C', 4, 'C');
    Network[3].rt.update('E', 2, 'E');

    // For E:
    Network[4].rt.update('D', 2, 'D');
    Network[4].rt.update('B', 9, 'B');

    cout << "Choose a Node from {A, B, C, D, E}: ";
    char node;
    cin >> node;
    cout << "Initial Routing table:\n";
    int idx = node - 'A';
    Network[idx].rt.display();
    DV(Network, idx);
    cout << "Final Routing table:\n";
    Network[idx].rt.display();

    return 0;
}
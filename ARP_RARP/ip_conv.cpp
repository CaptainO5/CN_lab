#include <iostream>

using namespace std;

const int NUM_NODES = 4;

string searchNW(string ip);

class Node {
    private:
        string mac;

        // Address table
        string ips[NUM_NODES];
        string macs[NUM_NODES];

    public:
        string ip;

        Node(string ip, string mac, string *ips){
            this -> ip = ip;
            this -> mac = mac;
            for (int i = 0; i < NUM_NODES; i++){
                macs[i] = "N/A";
                this -> ips[i] = ips[i];
                if (ip == ips[i]){
                    macs[i] = mac;
                }
            }
        }

        void lookup(string ip){
            int i = 0;
            for (string ip0: ips){
                if (ip0 == ip){
                    if (this -> macs[i] == "N/A") {
                        cout << "\nMAC Address Not found in the table, searching network\n";
                        mac = searchNW(ip);
                        if (mac != "N/A"){
                            this -> macs[i] = mac;
                            cout << "Address found: " << mac << "\n\n";
                        } else{
                            cout << "IP ADDRESS: NOT FOUND IN THE NETWORK\n";
                        }
                    } else {
                        cout << "\nMAC address: " << macs[i] << endl;
                    }
                    return;
                }
                i++;
            }
            cout << "\n";
        }

        string getMAC(){
            return mac;
        }
};


string ips[] = {"192.168.0.64", "192.168.0.60", "192.168.0.68", "132.147.3.3"};
Node Network[] = {
    Node("192.168.0.64", "00:A8:00:40:8E:F5", ips),
    Node("192.168.0.60", "00:A6:25:31:8E:22", ips),
    Node("192.168.0.68", "00:16:17:31:8E:F7", ips),
    Node("132.147.3.3", "00:16:BB:65:8E:08", ips)
};

string searchNW(string ip){
    for (Node n: Network){
        if (n.ip == ip)
            return n.getMAC();
    }
    return "N/A";
}

int main(){

    string temp;
    while(true){
        string sender;
        string reciever;
        cout << "Enter Sender IP: ";
        cin >> sender;
        cout << "Enter Reciever IP: ";
        cin >> reciever;
        int i = 0;
        for (; i < NUM_NODES; i++){
            if (Network[i].ip == sender){
                Network[i].lookup(reciever);
            }
        }
        if (i==NUM_NODES){
            cout << "Sender IP is incorrect\n\n";
        }

        cout << "Enter 'exit' to exit or '_' to continue\n";
        cin >> temp;
        if (temp.length() == 4)
            break;
    }


    return 0;
}
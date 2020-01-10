#include <bits/stdc++.h>

using namespace std;

map< string, pair<string, string> > parents;
map<string, string> genes;

string get_genes(string name) {
    if (genes.find(name) != genes.end()) return genes[name];
    else {
        pair<string, string> parents_names = parents[name];
        string first_gene = get_genes(parents_names.first);
        string second_gene = get_genes(parents_names.second);

        if ((first_gene != "non-existent" && second_gene != "non-existent") || first_gene == "dominant" || second_gene == "dominant") {
            if (first_gene == second_gene && first_gene == "dominant") genes[name] = "dominant";
            else if (first_gene != second_gene && first_gene != "non-existent" && second_gene != "non-existent") genes[name] = "dominant";
            else genes[name] = "recessive"; 
        } else genes[name] = "non-existent";

        return genes[name];
    }
}

int main() {
    int num_lines;
    scanf("%d", &num_lines);

    while (num_lines--) {
        string name, second_str;
        cin >> name >> second_str;

        if (second_str == "dominant" || second_str == "recessive" || second_str == "non-existent")
            genes[name] = second_str;
        else if (parents.find(second_str) == parents.end())
            parents[second_str] = {name, ""};
        else
            parents[second_str].second = name;
    }

    for (map< string, pair<string, string> >::iterator it = parents.begin(); it != parents.end(); it++)
        genes[it->first] = get_genes(it->first);

    for (map<string, string>::iterator it = genes.begin(); it != genes.end(); it++)
        printf("%s %s\n", (it->first).c_str(), (it->second).c_str());
}
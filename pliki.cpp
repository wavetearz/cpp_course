#include <iostream>
#include <fstream>
#include "lazycsv.hpp"

using namespace std;

enum FoldStatus {
    UPREGULATED,
    DOWNREGULATED,
    NORMAL
};

struct AnalysisStatus {
    string geneName;
    double foldChange;
    FoldStatus status;
};

double fold_change(double a, double b) {
    if (b == 0) { return 0; }
    if (b < 0 || a < 0) { return -1; }
    return b - a;
}

double is_upregulated(double a, double b) {
    if (fold_change(a, b) >= 2.0) return 1;
    return 0;
}

double is_downregulated(double a, double b) {
    if (fold_change(a, b) <= 0.5) return 1;
    return 0;
}

FoldStatus get_fold_status(double a, double b) {
    if (is_upregulated(a, b)) return UPREGULATED;
    if (is_downregulated(a, b)) return DOWNREGULATED;
    return NORMAL;
}

string fold_status_to_string(FoldStatus status) {
    switch (status) {
        case DOWNREGULATED:
            return "DOWNREGULATED";
        case UPREGULATED:
            return "UPREGULATED";
        case NORMAL:
            return "NORMAL";
    }
}

vector<AnalysisStatus> get_analysis_results(string filePath) {
    vector <AnalysisStatus> results;
    lazycsv::parser<> parser{ filePath };
    for (const auto row : parser)
    {
        const auto [gene, conditionA, conditionB] = row.cells(0, 1, 2); // indexes must be in ascending order
        AnalysisStatus result;
        result.geneName = gene.trimmed();
        double valA = stod(string(conditionA.trimmed()));
        double valB = stod(string(conditionB.trimmed()));
        result.foldChange = fold_change(valA, valB);
        result.status = get_fold_status(valA, valB);
        results.push_back(result);
    }
    return results;
}

int main() {
    vector<AnalysisStatus> results = get_analysis_results("/Users/vjasieg/CLionProjects/cpp_course/data.csv");
    cout << "Gene name" << "\t" << "Fold change" << "\t" << "Fold status" << "\n";
    for (const auto result : results) {
        cout << result.geneName << "\t" << result.foldChange << "\t" << fold_status_to_string(result.status) << endl;
    }
    return 0;
}
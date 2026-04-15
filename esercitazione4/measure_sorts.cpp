#include <iostream>
#include <vector>
#include <algorithm>

#include "bubble.h"
#include "insertion.h"
#include "selection.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf; 
    timecounter tc;

    for (int n = 4; n <= 8192; n *= 2) {

        double t_bubble = 0.0;
        double t_insertion = 0.0;
        double t_selection = 0.0;
        double t_std = 0.0;

   
            std::vector<int> v(n);
            rf.fill(v, -10000, 10000);

            auto v1 = v;
            auto v2 = v;
            auto v3 = v;
            auto v4 = v;

            // bubble
            tc.tic();
            bubble_sort(v1);
            t_bubble += tc.toc();

            // insertion
            tc.tic();
            insertion_sort(v2);
            t_insertion += tc.toc();

            // selection
            tc.tic();
            selection_sort(v3);
            t_selection += tc.toc();

            // sort()
            tc.tic();
            std::sort(v4.begin(), v4.end());
            t_std += tc.toc();
       
        
        std::cout << "lunghezza vettore: " << n << "\t" << "tempo bubble: " << t_bubble << "\t" << "tempo insertion: " << t_insertion << "\t" << "tempo selection: " << t_selection << "\t" << "tempo sort: " << t_std << "\n";
    }

    return 0;
}
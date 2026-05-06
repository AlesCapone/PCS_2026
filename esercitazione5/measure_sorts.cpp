#include <iostream>
#include <vector>
#include <algorithm>

#include "bubble.h"
#include "insertion.h"
#include "selection.h"
#include "mergesort.h"
#include "quicksort.h"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf; 
    timecounter tc;
	
	const int nv = 100;

    for (int n = 5; n <= 100; n += 5) {

        double t_bubble = 0.0;
        double t_insertion = 0.0;
        double t_selection = 0.0;
        double t_std = 0.0;
        double t_merge = 0.0;
        double t_quick = 0.0;
		
		
		std::vector<std::vector<int>> vec(nv);
		
		for (int i = 0; i < nv; i++) {
			vec[i].resize(n);
			rf.fill(vec[i], -10000, 10000);
    }

            // bubble
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];   
				bubble_sort(v);
				}
				t_bubble = tc.toc() / nv;

            // insertion
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];
				insertion_sort(v);
				}
				t_insertion = tc.toc() / nv;

            // selection
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];
				selection_sort(v);
				}
				t_selection = tc.toc() / nv;
				
            // sort()
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];
				std::sort(v.begin(), v.end());
				}
				t_std = tc.toc() / nv;
			
			// merge
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];
				merge_sort(v, 0, v.size() - 1);
				}
				t_merge = tc.toc() / nv;
			
			// quick
            tc.tic();
            for (int i = 0; i < nv; i++) {
				auto v = vec[i];
				quick_sort(v, 0, v.size() - 1);
				}
				t_quick = tc.toc() / nv;
        
        std::cout << "lunghezza vettore: " << n << "\t" << "tempo bubble: " << t_bubble << "\t" << "tempo insertion: " 
		<< t_insertion << "\t" << "tempo selection: " << t_selection << "\t" << "tempo sort: " << t_std << "\t" << "tempo merge: " << t_merge << "\t" << "tempo quick: " << t_quick << "\n";
    }

    return 0;
}
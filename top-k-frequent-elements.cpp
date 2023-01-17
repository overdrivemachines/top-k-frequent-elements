#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

// Works but is slow
vector<int> topKFrequent_slow(vector<int>& nums, int k) {
  unordered_map<int, int> umap;

  vector<int> result;

  // number of occurences of each element in the nums vector
  for (int num : nums) {
    umap[num]++;
  }

  // print umap
  for (auto u : umap) {
    cout << u.first << ":" << u.second << "\n";
  }


  int i = 0;
  // build results vector of k elements
  for (auto it = umap.begin(); i < k; it++, i++) {
    result.push_back(it->first);
  }

  // find lowest index and value in results vector
  int lowest_result_index = 0;
  int lowest_result_value = umap[result[0]];

  for (long unsigned int i = 0; i < result.size(); i++) {
    if (umap[result[i]] < lowest_result_value) {
      lowest_result_index = i;
      lowest_result_value = umap[result[i]];
    }
  }


  i = 0;
  for (auto u : umap) {
    if (i++ < k) {
      // do nothing
    }
    else {
      if (u.second > lowest_result_value) {
        result[lowest_result_index] = u.first;
        lowest_result_index = 0;
        lowest_result_value = umap[result[0]];
        for (long unsigned int i = 0; i < result.size(); i++) {
          if (umap[result[i]] < lowest_result_value) {
            lowest_result_index = i;
            lowest_result_value = umap[result[i]];
          }
        }
      }
    }
  }
  return result;
}


// Optimized and uses multimap
vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> result;
  int count = 0;
  unordered_map<int, int> umap;
  multimap<int, int, greater<int>> mmap;

  // umap will have number of occurences of each element in the nums vector
  for (int num : nums) {
    umap[num]++;
  }

  // Now umap contains something like:
  // umap[77]:4
  // umap[6]:2
  // umap[4]:2
  // umap[3]:1
  // umap[2]:2
  // umap[1]:3

  // Print umap
  // cout << "umap contents:\n";
  // for (auto u : umap)
  //   cout << u.first << ":" << u.second << "\n";


  // Insert into multimap mmap
  for (auto u : umap) {
    mmap.insert({u.second, u.first});
  }

  // Now mmap contains
  // 4:77
  // 3:1
  // 2:6
  // 2:4
  // 2:2
  // 1:3

  // Print mmap
  // cout << "mmap contents:\n";
  // for (auto m : mmap)
  //   cout << m.first << ":" << m.second << "\n";


  // get the first k elements of mmap
  for (auto m : mmap) {
    count++;
    if (count > k)
      return result;
    result.push_back(m.second);
  }

  return result;
}


// Prints the contents of a vector
void printv(vector<int> nums) {
  for (auto n : nums) {
    cout << n << " ";
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 6, 77, 77, 6, 77, 4, 77};
  int k = 3;

  printv(topKFrequent(nums, k));

  return 0;
}

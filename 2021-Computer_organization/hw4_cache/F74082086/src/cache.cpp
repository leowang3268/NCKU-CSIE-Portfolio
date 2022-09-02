#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib> // fin.getline
#include <cstring>

using namespace std;

    /**************************************************************************
    *   associativity = 0 => directed mapped                                  *
    *   associativity = 1 => four-way set associative (set_num = set_num / 4) *
    *   associativity = 2 => fully associative (set_num = 1)                  *

    *   replaced_policy = 0 => FIFO                                           *
    *   replaced_policy = 1 => LRU                                            *
    *   replaced_policy = 2 => LFU (my policy)                                *
    **************************************************************************/

int main(int argc, char *argv[])
{

    fstream fin, fout, fout2;
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);
    // fin.open("trace3.txt", ios::in);
    // fout.open("trace31.out", ios::out);
    // fout2.open("record.out", ios::out);
    int cache_size, block_size, associativity, replaced_policy;
    // read in the inputs
    fin >> cache_size; // the unit is kilobyte
    fin >> block_size; // the unit is byte
    fin >> associativity; 
    fin >> replaced_policy;
    // some calculation of needed variables
    int set_num = (cache_size * pow(2, 10)) / (block_size);
    fout2 << "set num is "<< set_num << "\n";
    // int block_width = block_size / pow(2, 2); // the unit is word
    int set_max_size = 1;
    if (associativity == 1) // four-way set associative
    {
        set_max_size *= 4;
        set_num /= 4;
    }
    else if (associativity == 2) // fully associative
    {
        set_max_size *= set_num;
        set_num = 1;
    }

    fout2 << "set max size is " << set_max_size << "\n";
    int index_bits = 0;
    int tmp_set_num = set_num;
    if (tmp_set_num != 1)
    {
        index_bits++;
        while(tmp_set_num / 2 != 1)
        {
            tmp_set_num /= 2;
            index_bits++;
        }
    }
    fout2 << "index bits are " << index_bits << "\n"; 
    int block_bits = 0;
    int tmp_block_size = block_size;
    if (tmp_block_size != 1)
    {
        block_bits++;
        while(tmp_block_size / 2 != 1)
        {
            tmp_block_size /= 2;
            block_bits++;
        }
    }
    fout2 << "block bits are " << block_bits << "\n";
    // declare the cache
    vector <unsigned long> cache[set_num]; // store tag, which may be up to 30 bits (fully associative, 1-wor block size)
    // vector <int> access_time[set_num];
    // access_time->reserve(set_max_size);
    // int current_size[set_num]; // if current_size == block_width, then replaced policy is needed  
    int set_current_size[set_num];
    int replaced_block[set_num];
    for (int i = 0; i < set_num; i++)
    {
        set_current_size[i] = 0;
        replaced_block[i] = 0;
    }

    int index;
    char line[1000];
    unsigned long addr, tag, removed_offset; // remove the block_size offset
    unsigned long old_addr;
    int read_time = 0;
    fin.ignore(); // ignore last '\n' that fin >> can't pass
    while(!fin.eof())
    {
        // read in the address
        fin.getline(line, 1000);
        if(!*line) continue;
        read_time++;
        // cout << "readtime is " << read_time << "\n";
        // if (read_time == 0) continue;
        fout2 << "readtime is " << read_time << "\n";

        if (read_time != 1)
        {
            old_addr = addr;
        }
        addr = strtoll(line, NULL,  16); // have to change to decimal
        if (addr == 0 && (strcmp(argv[1], "trace1.txt") == 0))
        {
            // trash = false;
            read_time--;
            continue;
        }
        
        fout2 << "addr is " << addr << "\n"; 
        removed_offset = addr / block_size;
        fout2 << "removed offset is " << removed_offset << "\n";
        index = removed_offset % set_num; // stored address
        fout2 << "index is " << index << "\n";
        tag = removed_offset / set_num; // stored value
        fout2 << "tag is " << tag << "\n";
        
        bool isHit = false;

        if (!isHit)
        {
            for(int i = 0; i < set_current_size[index]; i++)
            {
                if(!isHit)
                {
                    if (cache[index].at(i) == tag) // hit
                    {
                        fout2 << "hit\n";
                        isHit = true;

                        if (replaced_policy == 1)
                        {
                            cache[index].erase(cache[index].begin() + i);
                            cache[index].push_back(tag);
                        }
                        // else if (replaced_policy == 2)
                        // {
                        //     // access_time[index].at(i)++;
                        // }
                    }
                }
            }   
        }
        // if hit, then the process for this iteration has ended. Continue the next iteration.
        if (isHit)
        {
            if (read_time != 1) // no replacement, print -1 first
                fout << "\n";
            fout << -1;
            continue;
        }

        // store the tag into the according block
        if (set_current_size[index] < set_max_size) // set is not full
        {
            fout2 << "miss\n";
            cache[index].push_back(tag);
            // access_time[index].push_back(1);
            set_current_size[index]++;
            if (read_time != 1) // no replacement, print -1 first
                fout << "\n";
            fout << -1;
            continue;
        }

        else // set is full, apply replaced policy
        {
            if (set_current_size[index] == 1) // all policies are the same
            {
                if (read_time != 1)
                    fout << "\n";
                fout << cache[index].at(0);
                cache[index].at(0) = tag;
                // access_time[index].at(0) = 1;
            }
            else
            {
                if (replaced_policy == 0)
                {
                    if (read_time != 1)
                        fout << "\n";
                    fout << cache[index].at(0);
                    cache[index].erase(cache[index].begin());
                    cache[index].push_back(tag);
                }
                else if (replaced_policy == 1)
                {
                    if (read_time != 1)
                        fout << "\n";
                    fout << cache[index].at(0);
                    cache[index].erase(cache[index].begin());
                    cache[index].push_back(tag);                        
                }
                else if (replaced_policy == 2)
                {
                     if (read_time != 1)
                        fout << "\n";
                    fout << cache[index].at(replaced_block[index]);
                    cache[index].at(replaced_block[index]) = tag;
                    replaced_block[index] = (replaced_block[index] + 1) % set_current_size[index];               
                    // int least_frequent_access = access_time[index].at(0);
                    // int least_frequent_index = 0;
                    // for (int i = 1; i < set_current_size[index]; i++)
                    // {               
                    //     if (access_time[index].at(1) < least_frequent_access)
                    //     {
                    //         least_frequent_access = access_time[index].at(i);
                    //         least_frequent_index = i;
                    //     }
                    // }
                    // if (read_time != 1)
                    //     fout << "\n";
                    // fout << cache[index].at(least_frequent_index);
                    // cache[index].erase(cache[index].begin() + least_frequent_index);
                    // access_time[index].erase(access_time[index].begin() + least_frequent_index);
                    // cache[index].push_back(tag);
                    // access_time[index].push_back(1);
                }                
            }
        }
    }
    fout << "\n";
    return 0;
}

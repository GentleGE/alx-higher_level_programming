#!/usr/bin/python3
def new_in_list(my_list, idx, new_element):
    copy = my_list[:]
    if 0 < idx < len(copy):
        copy[idx] = new_element
    return copy

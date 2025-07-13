//
// Created by Samar on 05-07-2025.
//

#include "NibbleArray.h"

using namespace std;

NibbleArray::NibbleArray(const size_t size, const uint8_t val):
    size(size), arr(size/2+1, val){
}

uint8_t NibbleArray::get(const size_t pos) const {
    size_t index = pos/2;
    assert(pos <= this->size);
    uint8_t val = this->arr.at(index);

    if (pos%2 == 0) {
        return val>>4;
    }
    else {
        return val&0x0F;
    }
}

void NibbleArray::set(const size_t pos, const uint8_t val) {
    size_t index = pos/2;
    uint8_t curr_val = this->arr.at(index);

    assert(pos<=this->size);
    if (pos%2 == 0) {
        this->arr.at(index) = (curr_val & 0x0F)|(val<<4);
    }
    else {
        this->arr.at(index) = (curr_val & 0xF0)|(val&0x0F);
    }
}

unsigned char *NibbleArray::data() {
    return this->arr.data();
}

const uint8_t *NibbleArray::data() const {
    return this->arr.data();
}

size_t NibbleArray::storageSize() const {
    return this->arr.size();
}

void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);
    for (unsigned int i = 0; i < this->size; i++) {
        dest.push_back(this->get(i));
    }
}

void NibbleArray::reset(const uint8_t val) {
    fill(this->arr.begin(), this->arr.end(), val);
}




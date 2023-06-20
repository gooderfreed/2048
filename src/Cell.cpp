#include "../inc/Cell.h"
#include "../inc/utils.h"

Cell::Cell(float x, float y, float z, float size) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->size = size;
}

void Cell::draw() {
    float coords[3] = { x,y,z };
    parallelepiped(coords, size, size, 0.2, getColor(value));

    float numW = (size * 0.8f) / 8;
    float numH = size / 4;
    std::string nums = std::to_string(value);

    if ((nums.length() == 1 && nums != "0") || nums.length() > 1) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] - '0';
            float shift = -numW * nums.size() + numW * i * 2 + numW;

            if ((num != 5) && (num != 6)) {
                line(x + numW + shift - 0.035f, y + numH, x + numW + shift - 0.035f, y, z + 0.11f, getTextColor(value));
            }
            if (num != 2) {
                line(x + numW + shift - 0.035f, y, x + numW + shift - 0.035f, y - numH, z + 0.11f, getTextColor(value));
            }
            if (num != 1 && num != 0) {
                line(x - numW + shift + 0.035f, y, x + numW + shift - 0.035f, y, z + 0.11f, getTextColor(value));
            }
            if ((num != 1) && (num != 4)) {
                line(x - numW + shift + 0.030f, y - numH, x + numW + shift - 0.030f, y - numH, z + 0.11f, getTextColor(value));
                line(x - numW + shift + 0.030f, y + numH, x + numW + shift - 0.030f, y + numH, z + 0.11f, getTextColor(value));
            }
            if ((num != 1) && (num != 2) && (num != 3)) {
                line(x - numW + shift + 0.035f, y + numH, x - numW + shift + 0.035f, y, z + 0.11f, getTextColor(value));
            }
            if ((num != 1) && (num != 3) && (num != 4) && (num != 5)) {
                line(x - numW + shift + 0.035f, y, x - numW + shift + 0.035f, y - numH, z + 0.11f, getTextColor(value));
            }
        }
    }
}

void Cell::set_val(int val) {
    this->value = val;
}

int Cell::get_val() {
    return value;
}

// Task: Implement a class named 'RangeList'
// A pair of integers define a range, for example: [1, 5). This range includes integers: 1, 2, 3, and 4.
// A range list is an aggregate of these ranges: [1, 5), [10, 11), [100, 201)

class RangeList {

    /**
     * Init RangList
     */
    constructor() {
        this.result = {};
    }

    /**
     * Adds a range to the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    add(range = []) {
        console.log("Add：" + range);
        if (range.length != 2) {
            return;
        }

        let left = range[0];
        let right = range[1];

        let cur_key = 0;
        // 1. 查找第一个比 left 小的区间
        for (var key in this.result) {
            // 2. 如果没找到，忽略
            if (key > left) {
                continue;
            }

            cur_key = key;

            // 3. 如果找到，判断插入的值是否在区间内
            let cur_r = this.result[key];
            if (cur_r >= right) {
                return;
            }

            //  3.1 跳出循环，不做任何处理
            if (cur_r >= left) {
                //  3.2 不在区间内，将即将插入的left改为当前区间left值
                left = key;
                //  3.3 删除当前区间
                delete this.result[key];
            }
        }

        // 4. 查找比right小的分区，进行合并
        for (var key in this.result) {
            if (key > right || key <= cur_key) {
                continue;
            }

            right = Math.max(right, this.result[key]);
            delete this.result[key];
        }
        // 加入[left, right]
        this.result[left] = right;

        // 排序
        this.sort();
    }

    /**
     * Removes a range from the list
     * @param {Array<number>} range - Array of two integers that specify beginning and end of range.
     */
    remove(range = []) {
        console.log("remove：" + range);

        if (range.length != 2) {
            return;
        }

        let left = range[0];
        let right = range[1];

        // 1. 查找第一个比 left 小的区间
        let cur_key = 0;
        for (let key in this.result) {
            // 2. 如果没找到，忽略
            if (key > left) {
                continue;
            }

            cur_key = key;
            // 3. 如果当前区间包含要删除的区间 cur_l < left < right < cur_r
            if (this.result[key] >= right) {
                let cur_r = this.result[key];

                // 3.1 如果 cur_l = left, 则直接删除当前区间
                if (key == left) {
                    delete this.result[key];
                } else {
                    // 如果不是，区间分段, 第一段 [cur_l, left]
                    this.result[key] = left;
                }

                // 3.2 如果 cur_r != right, 第二段 [right, cur_r]
                if (cur_r != right) {
                    this.result[right] = cur_r;
                }

                // 3.3 如果 cur_r = right, 第二段为空 []
                return;
            } else if (this.result[key] >= left) {
                // 4. 如果当前区间包含一部分要删除的区间 cur_l < left < cur_r < right
                if (key == left) {
                    delete this.result[key]
                } else {
                    this.result[key] = left;
                }
            } else {
                continue;
            }
        }

        // 5. 遍历整个字典，对 left < cur_l < cur_r < right 进行处理
        for (let key in this.result) {
            if (key > right || key <= cur_key) {
                continue;
            }

            // 5.1 如果 cur_r = right, 直接删除该区间
            if (this.result[key] <= right) {
                delete this.result[key]
            } else {
                this.result[right] = this.result[key];
                delete this.result[key];
                break;
            }
        }

        // 排序
        this.sort();
    }

    /**
     * Prints out the list of ranges in the range list
     */
    print() {
        let str = "";
        for (var key in this.result) {
            str += "[" + key + "," + this.result[key] + ")";
        }
        console.log(str);
        console.log("---------------------------");
    }

    /**
     * Sort result
     */
    sort() {
        let res_keys = Object.keys(this.result).sort();
        var tmp = {};
        for (var key of res_keys) {
            tmp[key] = this.result[key];
        }
        this.result = tmp;
    }
}

module.exports = RangeList;
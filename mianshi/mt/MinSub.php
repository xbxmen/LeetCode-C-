<?php

$nums = [4, 2, 1, 5, 3, 2, 1];
$left = 0;
$right = count($nums) - 1;

$result = -1;
while ($left <= $right) {
    $mid = intval(($left + $right) / 2);

    if ($mid - 1 >= $left && $nums[$mid] > $nums[$mid - 1]) {
        $right = $mid - 1;
        continue;
    }

    if ($mid + 1 <= $right && $nums[$mid] > $nums[$mid + 1]) {
        $left = $mid + 1;
        continue;
    }

    $flag_left = false;
    if ($mid - 1 >= 0 && $nums[$mid] < $nums[$mid - 1]) {
        $flag_left = true;
    }
    if ($mid - 1 < 0) {
        $flag_left = true;
    }

    $flag_right = false;
    if ($mid + 1 <= count($nums) && $nums[$mid] < $nums[$mid + 1]) {
        $flag_right = true;
    }

    if ($mid + 1 > count($nums)) {
        $flag_right = true;
    }

    if ($flag_left && $flag_right) {
        $result = $mid;
        break;
    }
}

echo $result;

<?php
// 本题为考试多行输入输出规范示例，无需提交，不计分。

fscanf(STDIN, "%[^\n]s", $line);
//split line to array
$numbers = explode(" ", trim($line));

$result = [];
foreach ($numbers as $number) {
    if ($number > 0) {
        $result[] = $number;
        continue;
    } else {
        $left = $number;
        while (count($result) > 0) {
            if ($result[count($result) - 1] > 0) {
                $right = array_pop($result);
                if (abs($right) < abs($number)) {
                    continue;
                } else if (abs($right) > abs($number)) {
                    $left = 0;
                    $result[] = $right;
                    break;
                } else {
                    $left = 0;
                    break;
                }
            } else {
                break;
            }
        }

        if ($left != 0) {
            $result[] = $number;
        }
    }
}

echo '[' . implode(" ", $result) . ']';

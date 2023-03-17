<?php

// 1 26 27 28  53
// A    AA AB  BA

function ExcelColumn($number)
{
    $result = "";
    $map    = [
        '', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', ''
    ];
    while ($number > 26) {
        $tmp = $number % 26;
        $number = intval($number / 26);
        $result = chr($tmp + 64) . $result;
    }
    $result = chr($number + 64) . $result;

    return $result;
}

echo ExcelColumn(888) . PHP_EOL;

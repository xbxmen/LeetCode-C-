<?php
// 本题为考试多行输入输出规范示例，无需提交，不计分。

fscanf(STDIN, "%[^\n]s", $line);
//split line to array
$length = strlen($line);

$result  = [];
for ($i = 0; $i <= $length - 17; $i++) {
    $cur_str = substr($line, $i, 17);
    $cur_str = strtolower($cur_str);
    if (isOK($cur_str)) {
        $result[$cur_str] = 1;
    }
}

echo count($result);

// 01-02-03:04-05-06-07
function isOK($str)
{
    if (strpos('-', $str) && strpos(':', $str)) {
        return false;
    }

    $result = [];
    $poze = explode('-', $str);
    $mao  = explode(':', $str);
    if (count($poze) == 6) {
        $result = $poze;
    }

    if (count($mao) == 6) {
        $result = $mao;
    }

    if (empty($result)) {
        return false;
    }

    foreach ($result as $item) {
        if (strlen($item) != 2) {
            return false;
        }

        $item_1 = ($item[0] >= '0' && $item[0] <= '9') || ($item[0] >= 'a' && $item[0] <= 'f');
        $item_2 = ($item[1] >= '0' && $item[1] <= '9') || ($item[1] >= 'a' && $item[1] <= 'f');
        if ($item_1 && $item_2) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}

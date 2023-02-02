<?php

echo crc32("123123") % 16384;
echo PHP_EOL;
echo crc32("123123") & 16384;

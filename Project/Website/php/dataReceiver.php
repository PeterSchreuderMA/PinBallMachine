<?php

    $var1 = $_GET['score'];


    echo '<script type="js/scripts/web_text">',
    'ScoreAdd(' + $var1 + ');',
    '</script>';

    $fileContent = "Score: " . $var1 . "\n";

    $fileStatus = file_put_contents('savedData.txt', $fileContent.FILE_APPEND);

    if ($fileStatus != false)
    {
        echo "SUCCESS: Data written to file";
    }
    else
    {
        echo "FAIL: Could not write to file";
    }






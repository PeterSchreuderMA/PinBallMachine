<?php



    $jsonString = file_get_contents('savedData.json');
    $data = json_decode($jsonString, true);


    $data[0]['score'] = 0;









    /*
     $score = $_GET['score'];

    $myObj->score = 0;


    $myJson = json_encode($myObj);

    echo '<script type="js/scripts/web_text">',
    'ScoreAdd(' + $score + ');',
    '</script>';

    $fileContent = "Score: " . $var1 . "\n";



    $fileStatus = file_put_contents('savedData.json', $fileContent.FILE_APPEND);

    if ($fileStatus != false)
    {
        echo "SUCCESS: Data written to file";
    }
    else
    {
        echo "FAIL: Could not write to file";
    }

     */





<?php

$passWord = "PetersPinballMachine";


// - File -
$filePath = 'savedData.json';

$file = fopen($filePath, "w+") or die("Unable to open file");
// - Json -
$jsonLine = fread($file, "r+");

echo $jsonLine;
$jsonString = json_decode($jsonLine);


if ($jsonString == "")
{
    $jsonString['score'] = 0;
    $jsonString['balls'] = 0;
}


fclose($file);

$file = "";

// - Check the passWord
if (isset($_GET['passWord']))
{
    if ($_GET['passWord'] == $passWord)
    {
        echo 'Correct password';

        $file = fopen($filePath, "w+") or die("Unable to open file");

        $jsonLine = fread($file, "r+");
        echo $jsonLine;
        $jsonString = json_decode($jsonLine);



        // - Get the score
        if (isset($_GET['score']))
        {
            echo 'Get: ' . $_GET['score'];
            $score = $_GET['score'];

            $jsonString['score'] = $score;
        }

        // - Get the ball amount
        else if (isset($_GET['balls']))
        {
            echo 'Get: ' . $_GET['balls'];
            $balls = $_GET['balls'];

            $jsonString['balls'] = $balls;

        }

        echo $jsonString;

        $newJsonString = json_encode($jsonString);
        fwrite($file, $newJsonString);

        echo $newJsonString;
    }
    else
        echo 'Wrong password';
}
else
    echo 'No password';




if ($file != "")
    fclose($file);






//$jsonString = fread($file, "r+");//file_get_contents($filePath);
//echo $jsonString;
/*$data = json_decode($jsonString, true);


if (isset($_GET['score']))
{
    echo 'Get: ' . $_GET['score'];
    $score = $_GET['score'];

    $data['score'] = $score;

    $newJsonString = json_encode($data);
    fwrite($file, $newJsonString);
    //file_put_contents($filePath, $newJsonString);


}*/



//echo $data['score'];

//echo '<script> ScoreUpdate('. $data['score'] .'); </script>';//$data['score']













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















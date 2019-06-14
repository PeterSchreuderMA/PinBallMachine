<?php

$passWord = "5525";


// - File -
$filePath = 'savedData.json';


//echoText('filesize: ' . filesize($filePath));


// - If the file is empty or null fill the file
if (filesize($filePath) == 0)
{
    echoText('file empty');

    $file = fopen($filePath, "w") or die("Unable to open file");

    // Make up an json useble array
    $data['score'] = 0;
    $data['balls'] = 0;

    // Encode and write to the file
    $newJsonString = json_encode($data);
    fwrite($file, $newJsonString);

    // Close the file
    fclose($file);

    header("Refresh:0");
}


// - Check the passWord
if (isset($_GET['passWord']))
{
    if ($_GET['passWord'] == $passWord)
    {
        echoText('Correct password');

        $file = fopen($filePath, 'r') or die("Unable to open file");

        $jsonLine = fread($file, filesize($filePath));

        echoText('file contents: ' . $jsonLine);


        fclose($file);


        $file = fopen($filePath, "w") or die("Unable to open file");

        $jsonString = json_decode($jsonLine);

        //echoText('jsonString: ' . $jsonString);


        // - Get the score
        if (isset($_GET['score']))
        {
            echoText('Get: ' . $_GET['score']);
            $score = $_GET['score'];

            $jsonString->{'score'} = $score;
        }

        // - Get the ball amount
        if (isset($_GET['balls']))
        {
            echoText('Get: ' . $_GET['balls']);
            $balls = $_GET['balls'];

            $jsonString->{'balls'} = $balls;

        }

        //echoText('jsonString: ' . $jsonString);

        $newJsonString = json_encode($jsonString);
        fwrite($file, $newJsonString);

        fclose($file);

        echoText('newJsonString: ' . $newJsonString);
    }
    else
        echoText('Wrong password');
}



function echoText($_text)
{
    echo $_text . "<br>";
}



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















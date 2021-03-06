<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Pinball Machine</title>

    <!-- All the styles -->
    <link rel="stylesheet" href="css/style.css">

</head>

    <body>

        <div class="board">

            <div class="logo"><h1>Pinball Machine</h1></div>

            <div class="counters">

                <div id="score_amount" class="counter">Score: 00000000</div>
                <div id="ball_amount" class="counter">Ball: 0</div>

            </div>

        </div>



        <!-- Scripts -->
        <script src="js/scripts/textFunctions.js" charset="utf-8"></script>
        <script src="js/scripts/web_text.js" charset="utf-8"></script>


        <?php
        include("php/dataReceiver.php");
        ?>

    </body>



</html>
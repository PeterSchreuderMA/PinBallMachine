const score_text = document.getElementById('score_amount');
const ball_text = document.getElementById('ball_amount');

let score_amount = 0;
let ball_amount = 0;

let savedDataPath = "php/savedData.json";

//ScoreUpdate();

function update()
{
    window.requestAnimationFrame(update);

    if (score_amount != readJson(readTextFile(savedDataPath)).score)
        ScoreUpdateFormFile();
}

update();

//---------
//- Score -
//---------

function ScoreAdd(_amount)
{
    console.log("Added Score");
    score_amount += _amount;
    UpdateText(score_text, "Score: " + score_amount);
}

function ScoreUpdate(_amount)
{
    console.log("Updated Score");
    score_amount = _amount;
    UpdateText(score_text, "Score: " + score_amount);
}

function ScoreUpdateFormFile()
{
    console.log(readTextFile(savedDataPath));

    let _score = "";
    let _balls = "";


    //if (readJson(readTextFile(savedDataPath)).score != "")
        _score = Math.round(readJson(readTextFile(savedDataPath)).score);

    //if (readJson(readTextFile(savedDataPath)).balls != "")
        _balls = Math.round(readJson(readTextFile(savedDataPath)).balls);

    console.log("Score: " + _score);
    console.log("Balls: " + _balls);

    if (_score != "")
        score_amount = _score;
    else
        score_amount = 0;

    if (_balls != "")
        ball_amount = _balls;
    else
        score_amount = 0;


    console.log("Updated Score and Ball amout From File");
    UpdateText(score_text, "Score: " + score_amount);
    UpdateText(ball_text, "Balls: " + ball_amount);
}




//---------
//- Balls -
//---------

function BallsAdd(_amount)
{
    ball_amount += _amount;
    UpdateText(ball_text, "Balls: " + ball_amount);
}

function BallsUpdate(_amount)
{
    ball_amount = _amount;
    UpdateText(ball_text, "Balls: " + ball_amount);
}

function UpdateText(_textElement, _string)
{
    _textElement.innerHTML = _string;
    console.log("Updated Text");
}
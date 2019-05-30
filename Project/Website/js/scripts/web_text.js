const score_text = document.getElementById('score_amount');
const ball_text = document.getElementById('ball_amount');

let score_amount = 0;
let ball_amount = 0;


//---------
//- Score -
//---------

function ScoreAdd(_amount)
{
    score_amount += _amount;
    UpdateText(score_text, "Score: " + score_amount);
}

function ScoreUpdate(_amount)
{
    score_amount = _amount;
    UpdateText(score_text, "Score: " + score_amount);
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
}
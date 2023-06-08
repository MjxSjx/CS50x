// Define players objects with scores, buttons, and displays
const p1 =
{
    score: 0,
    button: document.querySelector('#p1Button'),
    display: document.querySelector('#p1Display')
};
const p2 =
{
    score: 0,
    button: document.querySelector('#p2Button'),
    display: document.querySelector('#p2Display')
};

// Define reset button and winning score selector, and set initial values
const resetButton = document.querySelector('#reset');
const winningScoreSelect = document.querySelector('#playto');
let winningScore = 3;
let isGameOver = false;

// Function to update scores and determine if game is over
function updateScores(player, opponent)
{
    if (!isGameOver) {
        player.score += 1;
        if (player.score >= winningScore && player.score - opponent.score >= 2) {
            isGameOver = true;
            player.display.classList.add('has-text-success');
            opponent.display.classList.add('has-text-danger');
            player.button.disabled = true;
            opponent.button.disabled = true;
        }
        player.display.textContent = player.score;
    }
}

// Add event listeners for player buttons and winning score selector
p1.button.addEventListener('click', function ()
{
    updateScores(p1, p2);
});
p2.button.addEventListener('click', function ()
{
    updateScores(p2, p1);
});
winningScoreSelect.addEventListener('change', function ()
{
    winningScore = parseInt(this.value);
    reset();
});

// Add event listener for reset button and define reset function
resetButton.addEventListener('click', reset);
function reset()
{
    isGameOver = false;
    for (let p of [p1, p2])
    {
        p.score = 0;
        p.display.textContent = 0;
        p.display.classList.remove('has-text-success', 'has-text-danger');
        p.button.disabled = false;
    }
}

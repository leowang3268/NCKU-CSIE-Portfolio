using UnityEngine;
using UnityEngine.SceneManagement; // For reloading scene etc
public class GameManager : MonoBehaviour {  

    bool gameHasEnded = false;

    public float restartDelay = 1f;

    public GameObject completeLevelUI; 

    public void CompleteLevel()
    {
        completeLevelUI.SetActive(true);
    }
    public void EndGame()
    {
        if (gameHasEnded == false)
        {
            gameHasEnded = true;
            Debug.Log("Game Over");
            // Restart game
            Invoke("Restart", restartDelay); // Invoke Restart() after restartDelay seconds
        }
    }

    void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name); // Load the current scene
    }

}

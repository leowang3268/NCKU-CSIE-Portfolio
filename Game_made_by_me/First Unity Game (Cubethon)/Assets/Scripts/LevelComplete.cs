using UnityEngine;
using UnityEngine.SceneManagement;

public class LevelComplete : MonoBehaviour {

	public void LoadNextLevel()
    {

        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1); // Load the scene whose build index is that of the current scene + 1  
    }

}

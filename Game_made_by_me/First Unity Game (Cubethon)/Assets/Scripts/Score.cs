using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour {

    public Transform player;
    public Text scoreText;

	void Update () {
        if (player.position.y >= 1)
            scoreText.text = player.position.z.ToString("0"); // add "0" in ToString() since we want the score to display as integer
	}
}

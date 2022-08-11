using UnityEngine;

public class EndTrigger : MonoBehaviour {

    public GameManager gameManager;

    void OnCollisionEnter(Collision collisioninfo)
    {
        if (collisioninfo.collider.name == "Player")
            gameManager.CompleteLevel();

    }
}

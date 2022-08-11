using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCollision : MonoBehaviour {

    public PlayerMovement movement;
    public AudioSource collideSound;
    public AudioSource winSound;

    void OnCollisionEnter (Collision collisioninfo)
    {
        if (collisioninfo.collider.tag == "Obstacle")
        {
            GetComponent<PlayerMovement>().enabled = false; // Disable the plaayer's movement
            FindObjectOfType<GameManager>().EndGame(); // Instead of declare a GameManager directly, which the GameManager will disappear with player being destroyed.
            collideSound.Play();
        }
        if (collisioninfo.collider.name == "END")
        {
            winSound.Play();
        }
    }
}

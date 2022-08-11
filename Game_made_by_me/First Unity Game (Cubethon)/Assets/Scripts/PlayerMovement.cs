using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {

    public Rigidbody rb; // A reference to the Rigidbody component named rb
    public float ForwardForce = 2000f;
    public float SidewayForce = 500f;
    public AudioSource fallSound;

    // We marked this as "Fixed"Update because we want to use physics in Unity
	void FixedUpdate () {
        // Add a forward force 
        rb.AddForce(0, 0, ForwardForce * Time.deltaTime);

        if (Input.GetKey("d"))
        {
            rb.AddForce(SidewayForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }

        if (Input.GetKey("a"))
        {
            rb.AddForce(-SidewayForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }

        if (rb.position.y < -1f)
        {
            FindObjectOfType<GameManager>().EndGame();
            fallSound.Play();
        }
    }
}

Question 1:
	When adding 50% loss to UDP, every so often(supposedly 50% of the time) there would be a loss of packets  in transmission. This would result in data inputted on client side not appearing to have reached the host and thus nothing is displayed in the host terminal. This makes sense because when data is lost in UDP it is unable to be retransmitted and thus the server just ignores it.

Question 2:
	When adding 50% loss to TCP, every so often there would be a loss of packets in transmission leading to the delay of certain data inputs. This is because TCP allows for the retransmission of data, so when packets are dropped or data is lost the server notifies the client to resend this data and thus all inputs after that data was lost is delayed until the initial lost data is retransmitted.

Question 3:
	The speed of TCP drastically slowed down. This could be because the data transmission rate is limited until the retransmission is complete. Once it is complete though the data is sent in one burst. 

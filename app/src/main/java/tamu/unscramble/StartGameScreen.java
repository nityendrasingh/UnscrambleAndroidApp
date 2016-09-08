package tamu.unscramble;

import android.content.Intent;
import android.graphics.Typeface;
import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;


public class StartGameScreen extends ServerLoginScreen {
    public static final String TAG = StartGameScreen.class.getSimpleName();
    String msgFromServer=null;
    private InetAddress ip;
    private Socket clientSocket;
    private TextView OnlineClientsTextViewFilled;
    private Button button;
    private TextView scrambledWord;
    private EditText unscrambledInput;
    private TextView result;
//    Typeface Collegiate_type = Typeface.createFromAsset(getAssets(),"fonts/COLLEGI1.TTF");
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start_game_screen);
        connect();
        OnlineClientsTextViewFilled = (TextView) findViewById(R.id.OnlineClientsTextViewFilled);
        scrambledWord = (TextView) findViewById(R.id.scrambledWord);
        scrambledWord.setVisibility(View.INVISIBLE);
//        scrambledWord.setTypeface(Collegiate_type);
        unscrambledInput = (EditText) findViewById(R.id.serverIP);
        unscrambledInput.setVisibility(View.INVISIBLE);
        result = (TextView) findViewById(R.id.result);
        result.setVisibility(View.INVISIBLE);
        button = (Button)findViewById(R.id.buttonStartGame);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                StartGameScreen.this.toastShow("Game is starting now!!");
                try {
                    PrintStream out = new PrintStream(clientSocket.getOutputStream());
                    String msg = "CPG\n";
                    out.println(msg);
                    out.flush();
                }catch(IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    private void toastShow(final String msg){
        runOnUiThread(new Runnable() {
            public void run() {
                Toast.makeText(getApplicationContext(), "Server : "
                        + msg, Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void prepare_game(){
        button.setText("Submit Response");
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                StartGameScreen.this.toastShow("Game is starting now!!");
                try {
                    PrintStream out = new PrintStream(clientSocket.getOutputStream());
                    String msg = "CAS"+unscrambledInput.getText().toString()+"\n";
                    out.println(msg);
                    out.flush();
                }catch(IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    private void reset_game(){
        OnlineClientsTextViewFilled.setVisibility(View.VISIBLE);
        button.setText("Restart Game");
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                StartGameScreen.this.toastShow("Game is starting now!!");
                try {
                    PrintStream out = new PrintStream(clientSocket.getOutputStream());
                    String msg = "CPG\n";
                    out.println(msg);
                    out.flush();
                }catch(IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }
    public class Client implements Runnable {
        Socket clientSocket;
        String clientName;
        char[] buffer = new char[100];
        public Client(Socket clientSocket, String clientName) {
            this.clientSocket = clientSocket;
            this.clientName = clientName;
        }
        @Override
        public void run() {
            android.os.Process.setThreadPriority(android.os.Process.THREAD_PRIORITY_BACKGROUND);
            try{
                String outStr = "CCO"+clientName;
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                out.println(outStr);
            } catch (IOException e) {

            }
            while (true) {
                try {
                    InputStreamReader reader = new InputStreamReader(clientSocket.getInputStream());
                    BufferedReader read = new BufferedReader(reader);
                    final String recvMessage = read.readLine();

//                    int numbytes = read.read(buffer,0,90);
//                    buffer[numbytes] = '\0';
//                    final String recvMessage = buffer.toString();
                    runOnUiThread(new Runnable() {
                        public void run() {
                            Log.d(TAG, recvMessage);
                            String header = recvMessage.substring(0,3);
                            String payload = recvMessage.substring(3);
                            if (header.equals("SCL")) {
                                OnlineClientsTextViewFilled.setText(payload);
                                OnlineClientsTextViewFilled.setVisibility(View.VISIBLE);
                            } else if (header.equals("SG1")) {
                                StartGameScreen.this.prepare_game();
                                scrambledWord.setText(payload);
                                scrambledWord.setTextColor(0xffffffff);
                                unscrambledInput.setTextColor(0xffffffff);
                                scrambledWord.setVisibility(View.VISIBLE);
                                unscrambledInput.setVisibility(View.VISIBLE);
                            } else if(header.equals("SRE")){
                                result.setText(payload);
                                result.setVisibility(View.VISIBLE);
                                result.setTextColor(0xffff0000);
                            } else if(header.equals("SRW")){
                                result.setText(payload);
                                result.setVisibility(View.VISIBLE);
                                result.setTextColor(0xfffbae3a);
                            } else if(header.equals("SFA")){
                                scrambledWord.setText("You Won !!");
                                scrambledWord.setVisibility(View.VISIBLE);
                                unscrambledInput.setVisibility(View.INVISIBLE);
                                result.setVisibility(View.INVISIBLE);
                                scrambledWord.setTextColor(0xff00ff00);
                                OnlineClientsTextViewFilled.setVisibility(View.INVISIBLE);
                                reset_game();
                            }else if(header.equals("SWA")){
                                scrambledWord.setText("You Won !!");
                                scrambledWord.setVisibility(View.VISIBLE);
                                unscrambledInput.setVisibility(View.INVISIBLE);
                                result.setVisibility(View.INVISIBLE);
                                scrambledWord.setTextColor(0xff00ff00);
                                OnlineClientsTextViewFilled.setVisibility(View.INVISIBLE);
                                reset_game();
                            }
                        }
                    });
                } catch (IOException e) {
                    break;
                }
            }

        }
    }

    private void connect(){
        Intent intent = getIntent();
        String clientName = intent.getStringExtra("clientName");
        String serverIP = intent.getStringExtra("serverIP");
        String serverPort = intent.getStringExtra("serverPort");
        toastShow(clientName+serverIP+serverPort);
        try {
            ip = InetAddress.getByName(serverIP);
            clientSocket = new Socket(ip,Integer.parseInt(serverPort));
            Thread Client = new Thread(new Client(clientSocket, clientName));
            Client.start();
        } catch (IOException e) {
            Toast.makeText(this,"Connect to " + ip + "failed.Exception" + e + "\n", Toast.LENGTH_LONG).show();

        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        Intent intent = getIntent();
        String clientName = intent.getStringExtra("clientName");
        String serverIP = intent.getStringExtra("serverIP");
        String serverPort = intent.getStringExtra("serverPort");
        toastShow(clientName+serverIP+serverPort);
        try {
            ip = InetAddress.getByName(serverIP);
            clientSocket = new Socket(ip,Integer.parseInt(serverPort));
            Thread Client = new Thread(new Client(clientSocket, clientName));
            Client.start();
        } catch (IOException e) {
            Toast.makeText(this,"Connect to " + ip + "failed.Exception" + e + "\n", Toast.LENGTH_LONG).show();

        }
        getMenuInflater().inflate(R.menu.start_game_screen, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}

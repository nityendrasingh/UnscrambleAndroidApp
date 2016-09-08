package tamu.unscramble;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class ServerLoginScreen extends Activity {
    EditText serverIP = null;
    EditText serverPort = null;
    EditText clientNameEditText = null;
    Button button = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_server_login_screen);

        serverIP = (EditText)findViewById(R.id.serverIP);
        serverPort = (EditText)findViewById(R.id.serverPort);
        clientNameEditText = (EditText)findViewById(R.id.clientNameEditText);
        button = (Button)findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                nextPage();
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
    private void nextPage(){
        Intent intentStartGame = new Intent(this, StartGameScreen.class);
        String clientName = clientNameEditText.getText().toString();
        if(clientName.equals("")){
            clientName = "CLtest1";
        }
        intentStartGame.putExtra("clientName",clientName);
        intentStartGame.putExtra("serverIP",serverIP.getText().toString());
        intentStartGame.putExtra("serverPort",serverPort.getText().toString());
//        toastShow(clientName+serverIP.getText().toString());
        startActivity(intentStartGame);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.server_login_screen, menu);
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

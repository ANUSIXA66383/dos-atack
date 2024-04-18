const https = require('https');
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the website: ', (website) => {
  const options = {
    hostname: website,
    port: 443,
    path: '/',
    method: 'GET'
  };

  function sendRequest() {
    const req = https.request(options, (res) => {
      console.log(`Response code: ${res.statusCode}`);
      res.on('data', (d) => {
        process.stdout.write(d);
      });
    });

    req.on('error', (e) => {
      console.error(e);
    });

    req.end();
  }

  setInterval(sendRequest, 0);

  rl.close();
});
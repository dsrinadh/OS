// Import required modules
const http = require('http');
const os = require('os');
const path = require('path');
const EventEmitter = require('events');

// Create Event Emitter object
const eventEmitter = new EventEmitter();

// Create a custom event
eventEmitter.on('requestReceived', () => {
    console.log('A request was received by the server');
});

// Create HTTP Server
const server = http.createServer((req, res) => {

    // Trigger event
    eventEmitter.emit('requestReceived');

    // Set response header
    res.writeHead(200, { 'Content-Type': 'text/html' });

    // OS Module Information
    const osInfo = `
        <h2>OS Module</h2>
        <p>Platform: ${os.platform()}</p>
        <p>Architecture: ${os.arch()}</p>
        <p>CPU Cores: ${os.cpus().length}</p>
        <p>Home Directory: ${os.homedir()}</p>
    `;

    // Path Module Information
    const filePath = path.join(__dirname, 'files', 'test.txt');

    const pathInfo = `
        <h2>Path Module</h2>
        <p>Joined Path: ${filePath}</p>
        <p>File Extension: ${path.extname(filePath)}</p>
        <p>Base Name: ${path.basename(filePath)}</p>
        <p>Directory Name: ${path.dirname(filePath)}</p>
    `;

    // Response Output
    res.write(`
        <html>
        <body>
            <h1>Custom Node.js Server</h1>
            ${osInfo}
            ${pathInfo}
        </body>
        </html>
    `);

    res.end();
});

// Define Port
const PORT = 3000;

// Start Server
server.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});

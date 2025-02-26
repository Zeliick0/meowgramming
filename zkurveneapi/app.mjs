import express from 'express';
import axios from 'axios';

const app = express();
const port = 3000;

app.use(express.static('public'));

app.get('/', async (req, res) => {
  try {
    const URL = 'https://rickandmortyapi.com/api/character/';
    const randomId = Math.floor(Math.random() * 826) + 1;
    const response = await axios.get(URL + randomId);

    console.log('Image URL:', response.data.image);

    res.send(`
    <!DOCTYPE html>
    <html lang="cs">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Rick and Morty Random Character</title>
        <style>
            body { 
                text-align: center; 
                font-family: 'Arial', sans-serif; 
                background-color: #1e1e1e; 
                color: white; 
                display: flex;
                flex-direction: column;
                justify-content: center;
                align-items: center;
                height: 100vh;
            }
            .container {
                background: #333;
                padding: 20px; 
                border-radius: 10px;
                box-shadow: 0px 0px 15px rgba(255, 255, 255, 0.2);
                max-width: 400px;
                border: 2px solid red;
            }
            img { 
                width: 100%;
                max-height: 300px;
                object-fit: cover;
            }
            h2 {
                margin-bottom: 10px;
            }
            p {
                margin: 5px 0;
            }
        </style>
    </head>
    <body>

        <div class="container">
            <h2>${response.data.name}</h2>
            <img src="${response.data.image}" alt="${response.data.name}">
            <p><strong>Status:</strong> ${response.data.status}</p>
            <p><strong>Species:</strong> ${response.data.species}</p>
            <p><strong>Gender:</strong> ${response.data.gender}</p>
            <p><strong>Origin:</strong> ${response.data.origin.name}</p>
            
        </div>
    </body>
    </html> 
    `);
  } catch (error) {
    console.error('Chyba při načítání postavy:', error.message);
    res
      .status(500)
      .send('<h2>Chyba při načítání postavy. Zkuste to znovu.</h2>');
  }
});

app.listen(port, () => {
  console.log(`Server běží na http://localhost:${port}`);
});

import express from 'express';
import axios from 'axios';

const app = express();
const port = 3000;

app.use(express.static('public'));

app.get('/', async (req, res) => {
  try {
    const authorId = 'OL4490678A';
    const authorURL = `https://openlibrary.org/authors/${authorId}.json`;
    const booksURL = `https://openlibrary.org/authors/${authorId}/works.json`;

    const authorResponse = await axios.get(authorURL);
    const booksResponse = await axios.get(booksURL);

    const authorData = authorResponse.data;
    const booksData = booksResponse.data.entries;

    console.log('Author Data:', authorData);

    const authorPhotoUrl =
      authorData.photos && authorData.photos.length > 0
        ? `https://covers.openlibrary.org/b/id/${authorData.photos[0]}-L.jpg`
        : null;

    const bookItems = await Promise.all(
      booksData.map(async (book) => {
        const bookCoverUrl =
          book.covers && book.covers[0]Laozi
            ? `https://covers.openlibrary.org/b/id/${book.covers[0]}-L.jpg`
            : '';

        const bookDetailURL = `https://openlibrary.org${book.key}.json`;
        const bookDetailResponse = await axios.get(bookDetailURL);
        const bookDetail = bookDetailResponse.data;

        console.log('Book Detail:', bookDetail);
        const createdYear = bookDetail.created
          ? new Date(bookDetail.created.value).getFullYear()
          : 'N/A';

        return `
          <div class="book">
            <div class="book-image">
              ${
                bookCoverUrl
                  ? `<img src="${bookCoverUrl}" alt="Cover of ${book.title}">`
                  : '<p>No cover available</p>'
              }
            </div>
            <div class="book-info">
              <h3>${book.title}</h3>
              <p><strong>Publish date:</strong> ${createdYear}</p>
              <p><strong>Subjects:</strong> ${
                book.subjects ? book.subjects.join(', ') : 'N/A'
              }</p>
            </div>
          </div>
        `;
      })
    );

    const authorBio = authorData.bio.value
      ? `<p><strong>Biography:</strong> ${authorData.bio.value}</p>`
      : '';

    res.send(`
    <!DOCTYPE html>
    <html lang="cs">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Author Books - ${authorData.name}</title>
        <style>
        h2 {
          text-decoration: underline;
        }

        body { 
          text-align: center; 
          font-family: 'Arial', sans-serif; 
          background-color: #1e1e1e; 
          color: white; 
          margin: 0;
          padding: 0;
          overflow-x: hidden;
          height: 100vh;
      }
      
      .container {
          display: flex;
          flex-direction: column;
          align-items: center;
          justify-content: flex-start;
          width: 90%;
          max-width: 1200px;
          margin: 20px auto;
          background-color: rgba(255, 255, 255, 0.1);
          border-radius: 10px;
          padding: 20px;
          box-shadow: 0px 0px 15px rgba(255, 255, 255, 0.2);
          backdrop-filter: blur(10px);
          overflow-y: auto;
          max-height: 90vh;
      }
      
      .author-info {
          margin-bottom: 40px;
          text-align: center;
          display: flex;
          align-items: center;
          justify-content: center;
      }
      
      .author-info h2 {
          margin: 10px 20px 10px 0;
      }
      
      .books-list {
          display: flex;
          flex-wrap: wrap;
          justify-content: center;
          gap: 20px;
          width: 100%;
      }
      
      .book {
          display: flex;
          flex-direction: column;
          align-items: center;
          background-color: rgba(0, 0, 0, 0.5);
          padding: 15px;
          border-radius: 10px;
          width: 250px;
          box-shadow: 0px 0px 10px rgba(255, 255, 255, 0.2);
          backdrop-filter: blur(5px);
          overflow: hidden;
          max-width: 100%; 
          text-align: center;
      }
      
      .book-image {
          flex: 1;
          margin-bottom: 15px;
          max-width: 100%;
      }
      
      .book-image img {
          width: 100%;
          height: auto;
          border-radius: 10px;
      }
      
      .book-info {
          flex: 2;
          padding: 10px;
          text-align: left;
          color: #fff;
      }
      
      .book-info h3 {
          margin-bottom: 10px;
      }
      
      .book-info p {
          margin: 5px 0;
      }
      
      .book-info strong {
          color: #ff9800;
      }

      .author-image {
          width: 150px;
          height: 150px;
          border: 2px solid #fff; 
          border-radius: 5px;
      }
        </style>
    </head>
    <body>
        <div class="container">
            <div class="author-info">
                <h2>${authorData.name}</h2>
                ${
                  authorPhotoUrl
                    ? `<img src="${authorPhotoUrl}" alt="Photo of ${authorData.name}" class="author-image">`
                    : ''
                }
            </div>

            <p><strong>Birth Year:</strong> ${
              authorData.birth_date || 'N/A'
            }</p>
            <p><strong>Death Year:</strong> ${
              authorData.death_date || 'N/A'
            }</p>
            ${authorBio}

            <div class="books-list">
                ${bookItems.join('')}
            </div>
        </div>
    </body>
    </html>
    `);
  } catch (error) {
    console.error('Error fetching author data:', error.message);
    res
      .status(500)
      .send('<h2>Error fetching author data. Please try again later.</h2>');
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});

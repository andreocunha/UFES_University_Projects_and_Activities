# for-editor-markdown

based on [for-editor](https://github.com/kkfor/for-editor)

### Instalação

```js
npm install for-editor-markdown
```

### Usar

```js
import React, { Component } from 'react'
import ReactDOM from 'react-dom'
import MdEditor from 'for-editor-markdown'

class App extends Component {
  constructor() {
    super()
    this.state = {
      value: ''
    }
  }

  handleChange(value) {
    this.setState({
      value
    })
  }

  render() {
    const { value } = this.state
    return <MdEditor value={value} onChange={() => this.handleChange()} />
  }
}

ReactDOM.render(<App />, document.getElementById('root'))
```

### Api

#### Atributos

| name        | type    | default     | description                        |
| ----------- | ------- | ----------- | ---------------------------------- |
| value       | String  | -           | Conteúdo da caixa de entrada                         |
| placeholder | String  | Comece a editar... | Placeholder text                           |
| lineNum     | Boolean | true        | Se deve exibir o número da linha                       |
| style       | Object  | -           | Estilo do editor                         |
| height      | String  | 600px       | Altura de editor                         |
| preview     | Boolean | false       | Modo de pré-visualização                           |
| expand      | Boolean | false       | Modo tela cheia                           |
| subfield    | Boolean | false       | Modo de coluna dupla (válido quando o modo de visualização está ativado)       |
| language    | String  | pt-BR       | Idioma (suporte pt-BR: português do Brasil, en: inglês) |
| toolbar     | Object  | Do seguinte modo        | Barra de ferramentas personalizada                       |

```js

toolbar: {
  h1: true,
  h2: true,
  h3: true,
  h4: true,
  img: true,
  link: true,
  code: true,
  preview: true,
  expand: true,
  undo: true,
  redo: true,
  save: true,
  subfield: true,
}
```

#### Eventos

| name     | params   | default | description    |
| -------- | ------------- | ------- | -------------- |
| onChange | String: value | -       | Retorno de chamada quando o conteúdo muda |
| onSave   | String: value | -       | Retorno de chamada ao salvar     |
| addImg   | File: file    | -       | Retorno de chamada ao adicionar uma imagem |

##### Upload de imagem

```js
class App extends Component {
  constructor() {
    super()
    this.state = {
      value: '',
    }
    this.$vm = React.createRef()
  }

  handleChange(value) {
    this.setState({
      value
    })
  }

  addImg($file) {
    this.$vm.current.$img2Url($file.name, 'file_url')
    console.log($file)
  }

  render() {
    const { value } = this.state

    return (
      <MdEditor
        ref={this.$vm}
        value={value}
        addImg={($file) => this.addImg($file)}
        onChange={value => this.handleChange(value)}
      />
    )
  }
}
```

#### Teclas de atalho

| name   | description  |
| ------ | ------------ |
| tab    | Recuo de dois espaços |
| ctrl+s | Salva         |
| ctrl+z | Passo anterior       |
| ctrl+y | Próxima Etapa       |


### Licença

for-editor-markdown is [MIT Licence](./LICENSE).

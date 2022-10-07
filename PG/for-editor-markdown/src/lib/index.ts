import ptBR from './lang/pt-BR/index.json'
import en from './lang/en/index.json'
import { IToolbar, IWords } from '../index'
export interface ICONFIG {
  language: {
    'pt-BR': IWords
    en: IWords
    [key: string]: IWords
  }
  langList: string[]
  toolbar: IToolbar
}

export const CONFIG: ICONFIG = {
  language: {
    'pt-BR': ptBR,
    en,
  },
  langList: ['pt-BR', 'en'],
  toolbar: {
    h1: true,
    h2: true,
    h3: true,
    // h4: true,
    img: true,
    link: true,
    code: true,
    preview: true,
    expand: true,
    undo: true,
    redo: true,
    // save: true,
    subfield: true
  }
}
